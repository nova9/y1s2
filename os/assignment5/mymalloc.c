#include <stdio.h>
#include <stddef.h>
#include "mymalloc.h"

#define MEM_SIZE 25000

char memory[MEM_SIZE];


Block *freeList = (void *)memory;

void initialize()
{
  freeList->size = MEM_SIZE - sizeof(Block);
  freeList->free = 1;
  freeList->next = NULL;
}

void split(Block *fitting_slot, size_t size)
{
  Block *new = (void *)((void *)fitting_slot + size + sizeof(Block));
  new->size = (fitting_slot->size) - size - sizeof(Block);
  new->free = 1;
  new->next = fitting_slot->next;
  fitting_slot->size = size;
  fitting_slot->free = 0;
  fitting_slot->next = new;
}

void *MyMalloc(size_t noOfBytes)
{
  Block *curr, *prev;
  void *result;
  if (!(freeList->size))
  {
    initialize();
    printf("Memory initialized\n");
  }
  curr = freeList;
  while ((((curr->size) < noOfBytes) || ((curr->free) == 0)) && (curr->next != NULL))
  {
    prev = curr;
    curr = curr->next;
    printf("One block checked\n");
  }

  if ((curr->size) == noOfBytes)
  {
    curr->free = 0;
    result = (void *)(++curr);
    printf("Exact fitting block allocated\n");
    return result;
  }

  else if ((curr->size) > (noOfBytes + sizeof(Block)))
  {
    split(curr, noOfBytes);
    result = (void *)(++curr);
    printf("Fitting block allocated with a split\n");
    return result;
  }
  else
  {
    result = NULL;
    printf("Sorry. No sufficient memory to allocate\n");
    return result;
  }
}

void merge()
{
  Block *curr, *prev;
  curr = freeList;
  while ((curr->next) != NULL)
  {
    if ((curr->free) && (curr->next->free))
    {
      curr->size += (curr->next->size) + sizeof(Block);
      curr->next = curr->next->next;
    }
    prev = curr;
    curr = curr->next;
  }
}

void MyFree(void *ptr)
{
  if (((void *)memory <= ptr) && (ptr <= (void *)(memory + 20000)))
  {
    Block *curr = ptr;
    --curr;
    curr->free = 1;
    merge();
  }
  else
    printf("Please provide a valid pointer allocated by MyMalloc\n");
}
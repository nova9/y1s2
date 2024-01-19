#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stdio.h>
#include <stddef.h>

typedef struct Block Block;
struct Block
{
  size_t size;
  int free;
  Block *next;
};

void initialize();

void split(Block *fitting_slot, size_t size);

void *MyMalloc(size_t noOfBytes);

void merge();

void MyFree(void *ptr);

#endif
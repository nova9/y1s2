#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"


Node *createNode(int data)
{
  Node *newNode = malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}


void insertAtBeginning(Node **headRef, int data)
{
  Node *newNode = createNode(data);
  newNode->next = *headRef;
  *headRef = newNode;
}


void displayList( Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}


void deleteList(Node **headRef)
{
  Node *current = *headRef;
  Node *next;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }

  *headRef = NULL;
}

// int main() {
//     struct Node* head = NULL;

//     insertAtBeginning(&head, 5);
//     insertAtBeginning(&head, 10);
//     insertAtBeginning(&head, 15);
//     insertAtBeginning(&head, 20);

//     printf("Linked List: ");
//     displayList(head);

//     deleteList(&head);

//     return 0;
// }

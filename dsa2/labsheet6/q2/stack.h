#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct
{
  int top;
  unsigned capacity;
  Node **array;
} Stack;

Stack *createStack(unsigned capacity);

bool isFull(Stack *stack);

bool isEmpty(Stack *stack);

void push(Stack *stack, Node *node);

Node *pop(Stack *stack);

#endif
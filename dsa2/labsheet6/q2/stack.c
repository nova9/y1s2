#include "node.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
  int top;
  unsigned capacity;
  Node **array;
} Stack;

Stack *createStack(unsigned capacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (Node **)malloc(stack->capacity * sizeof(Node *));
  if (stack->array == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  return stack;
}

bool isFull(Stack *stack)
{
  return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack)
{
  return stack->top == -1;
}

void push(Stack *stack, Node *node)
{
  if (isFull(stack))
  {
    return;
  }
  stack->array[++stack->top] = node;
}

Node *pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    return NULL;
  }
  return stack->array[stack->top--];
}
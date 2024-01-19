#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

typedef struct
{
  int front, rear, size, capacity;
  int *array;
} Queue;

Queue *createQueue(int capacity);


int isFull(Queue *queue);


int isEmpty(Queue *queue);


void enqueue(Queue *queue, int);


int dequeue(Queue *queue);

#endif
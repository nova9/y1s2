#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"


Queue *createQueue(int capacity)
{
  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = malloc(queue->capacity * sizeof(int));
  if (queue->array == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  return queue;
}


int isFull(Queue *queue)
{
  return (queue->size == queue->capacity);
}


int isEmpty(Queue *queue)
{
  return (queue->size == 0);
}


void enqueue(Queue *queue, int value)
{
  if (isFull(queue))
  {
    return;
  }
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = value;
  queue->size = queue->size + 1;
}


int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    return -1;
  }
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include "queue.h"

Graph *createGraph(int number_of_vertices)
{
  Graph *graph = malloc(sizeof(Graph));
  graph->number_of_vertices = number_of_vertices;
  graph->list = malloc(graph->number_of_vertices * sizeof(Node *));
  return graph;
}

void addEdge(Graph *graph, int u, int v)
{
  if (u >= graph->number_of_vertices || v >= graph->number_of_vertices)
  {
    printf("Invalid vertex\n");
    return;
  }

  insertAtBeginning(&graph->list[u], v);

  // Node *newNode = createNode(v);
  // newNode->next = graph->list[u];
  // graph->list[u] = newNode;
}

void bfs(Graph *graph)
{
  int visited[graph->number_of_vertices];
  for (int i = 0; i < graph->number_of_vertices; i++)
  {
    visited[i] = 0;
  }

  Queue *queue = createQueue(graph->number_of_vertices);

  enqueue(queue, 0);
  visited[0] = 1;

  while (!isEmpty(queue))
  {
    int s = dequeue(queue);
    printf("%d ", s);

    Node *current = graph->list[s];

    while (current != NULL)
    {
      // printf("dd");
      if (visited[current->data])
      {
      }
      else
      {
        enqueue(queue, current->data);
        visited[current->data] = 1;
      }
      current = current->next;
    }
  }
}

void printGraph(Graph *graph)
{
  printf("Adjacency List Representation:\n");
  for (int i = 0; i < graph->number_of_vertices; i++)
  {
    printf("%d -> ", i);
    Node *current = graph->list[i];
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}
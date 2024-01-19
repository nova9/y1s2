#include <stdio.h>
#include "graph.h"
#include "queue.h"

int main()
{
  Graph *graph = createGraph(8);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 6);
  addEdge(graph, 4, 7);

  // printGraph(graph);

  bfs(graph);
}
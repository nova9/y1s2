#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

typedef struct
{
    int number_of_vertices;
    Node **list;
} Graph;

Graph *createGraph(int);

void addEdge(Graph *, int, int);

void printGraph(Graph *);

void bfs(Graph *graph);

#endif
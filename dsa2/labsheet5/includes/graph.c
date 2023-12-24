#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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

    Node *newNode = createNode(v);
    newNode->next = graph->list[u];
    graph->list[u] = newNode;
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
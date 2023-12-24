#include <stdio.h>
#include "../includes/graph.h"

int main()
{
    int vertices, edges;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    Graph *graph = createGraph(vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter pairs of vertices representing edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++)
    {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        if (vertex1 >= vertices || vertex2 >= vertices || vertex1 < 0 || vertex2 < 0)
        {
            printf("Invalid edge! Please enter valid vertices.\n");
            i--;
            continue;
        }

        addEdge(graph, vertex1, vertex2);
        // addEdge(graph, vertex2, vertex1);
    }

    printGraph(graph);
}
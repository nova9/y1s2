#include <iostream>
#include "Graph.hpp"

using namespace std;

int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add some edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.addVertex();
    graph.addEdge(6, 4);

    // Print the adjacency list representation of the graph
    graph.printGraph();
}
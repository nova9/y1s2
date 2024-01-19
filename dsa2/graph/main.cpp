#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{
    // Create a graph with 6 (until 5) vertices
    Graph graph(5);

    // printAdjList(graph.adjList);

    // Add some edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    // graph.addEdge(5, 4);


    // // Print the adjacency list representation of the graph
    // graph.printGraph();

    // graph.bft_with_distance();

    // graph.bft();

    graph.dft();
    graph.dft_with_dfs_number();
}
#include <iostream>
#include "Graph.hpp"

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    // adjList[v].push_back(u); // For undirected graph
}

void Graph::addVertex()
{
    adjList.resize(adjList.size() + 1);
}

void Graph::printGraph()
{
    for (int i = 0; i < adjList.size(); i++)
    {
        std::cout << i << ": ";
        for (const auto &destination : adjList[i])
        {
            std::cout << destination << " ";
        }
        std::cout << std::endl;
    }
}
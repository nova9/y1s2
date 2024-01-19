#include <iostream>
#include "graph.hpp"
#include <queue>
#include <stack>
#include <string>

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
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

void Graph::bft()
{
    std::queue<int> frontier;
    frontier.push(0);
    Color nodeColors[adjList.size()];
    nodeColors[0] = GRAY;
    for (int i = 1; i <= adjList.size(); i++)
    {
        nodeColors[i] = WHITE;
    }

    while (!frontier.empty())
    {
        int g = frontier.front();
        frontier.pop();
        for (int i = 0; i < adjList[g].size(); i++)
        {
            int v = adjList[g][i];
            if (nodeColors[v] == WHITE)
            {
                frontier.push(v);
                nodeColors[v] = GRAY;
            }
        }
        nodeColors[g] = BLACK;
        std::cout << g << " ";
    }
    std::cout << std::endl;
}


void Graph::bft_with_distance()
{
    std::queue<int> frontier;
    frontier.push(0);
    int node_distance[adjList.size()];
    node_distance[0] = 0;

    for (int i = 1; i <= adjList.size(); i++)
    {
        node_distance[i] = -1;
    }

    while (!frontier.empty())
    {
        int g = frontier.front();
        frontier.pop();
        for (int i = 0; i < adjList[g].size(); i++)
        {
            int v = adjList[g][i];
            if (node_distance[v] == -1)
            {
                frontier.push(v);
                node_distance[v] = node_distance[g] + 1;
            }
        }
        std::cout << g << " ";
    }
    std::cout << std::endl;
}

void Graph::dft()
{
    std::stack<int> frontier;
    frontier.push(0);
    Color nodeColors[adjList.size()];
    nodeColors[0] = GRAY;
    for (int i = 1; i <= adjList.size(); i++)
    {
        nodeColors[i] = WHITE;
    }

    while (!frontier.empty())
    {
        int g = frontier.top();
        frontier.pop();
        for (int i = 0; i < adjList[g].size(); i++)
        {
            int v = adjList[g][i];
            if (nodeColors[v] == WHITE)
            {
                frontier.push(v);
                nodeColors[v] = GRAY;
            }
        }
        nodeColors[g] = BLACK;
        std::cout << g << " ";
    }
    std::cout << std::endl;
}

void Graph::dft_with_dfs_number()
{
    std::stack<int> frontier;
    frontier.push(0);
    int node_dfs_number[adjList.size()];
    int nextDfs = 0;

    for (int i = 1; i <= adjList.size(); i++)
    {
        node_dfs_number[i] = -1;
    }

    while (!frontier.empty())
    {
        int g = frontier.top();
        frontier.pop();
        if (node_dfs_number[g] > -1) {
            continue;
        }
        node_dfs_number[g] = nextDfs++;
        for (int i = 0; i < adjList[g].size(); i++)
        {
            int v = adjList[g][i];
            if (node_dfs_number[v] == -1)
            {
                frontier.push(v);
            }
        }
        std::cout << g << "(" << node_dfs_number[g] << ")" << " ";
    }
    std::cout << std::endl;
}
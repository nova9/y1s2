#pragma once
#include <vector>

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

class Graph
{
public:
    std::vector<std::vector<int>> adjList;

public:
    Graph(int vertices) : adjList(vertices) {} // TODO What is happening here

    void addEdge(int, int);

    void addVertex();

    void printGraph();

    void bft();

    void bft_with_distance();

    void dft();

    void edge_classification();

    void dft_with_dfs_number();
};
#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjList;

public:
    Graph(int vertices) : adjList(vertices) {}

    void addEdge(int, int) {}

    void addVertex();

    void printGraph();
};
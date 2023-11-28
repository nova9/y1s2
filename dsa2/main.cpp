#include <iostream>
#include <map>
#include <deque>

using namespace std;

class Stack
{
private:
    vector<string> array;

public:
    void push(string value)
    {
        array.push_back(value);
    }

    string pop()
    {
        string temp = array.back();
        array.pop_back();
        return temp;
    }

    string peek()
    {
        return array.back();
    }

    int top()
    {
        return array.size();
    }
};

class Queue
{
private:
    deque<string> array;

public:
    void enqueue(string value)
    {
        array.push_back(value);
    }

    string dequeue()
    {
        string temp = array.front();
        array.pop_front();
        return temp;
    }

    int length()
    {
        return array.size();
    }
};

class Graph
{
private:
    map<string, vector<string>> adjacencyList;

    void dfs_iterative()
    {
        Stack stack;
        stack.push(adjacencyList.begin()->first);

        while (stack.top() > 0)
        {
            string current = stack.pop();
            cout << current << " ";

            for (int i = 0; i < adjacencyList[current].size(); i++)
            {
                stack.push(adjacencyList[current].at(i));
            }
        }
        cout << endl;
    }

    void dfs_recursive(string source)
    {
        cout << source << " ";
        for (int i = 0; i < adjacencyList[source].size(); i++)
        {
            dfs_recursive(adjacencyList[source].at(i));
        }
    }

public:
    void addEdge(string source, string destination)
    {
        adjacencyList[source].push_back(destination);
    }

    void display()
    {
        for (const auto &item : adjacencyList)
        {
            cout << item.first << ": ";
            for (int i = 0; i < item.second.size(); ++i)
            {
                cout << item.second.at(i) << " ";
            }
            cout << endl;
        }
    }

    void dfs()
    {
        // dfs_iterative();
        dfs_recursive(adjacencyList.begin()->first);
        cout << endl;
    }

    void bfs()
    {
        Queue queue;
        queue.enqueue(adjacencyList.begin()->first);

        while (queue.length() > 0)
        {
            string current = queue.dequeue();
            cout << current << " ";
            for (int i = 0; i < adjacencyList[current].size(); i++)
            {
                queue.enqueue(adjacencyList[current].at(i));
            }
        }
        cout << endl;
    }

    bool has_path(string source, string destination) // time = O(n^2) space = O(n)
    {
        if (source == destination)
            return true;
        for (int i = 0; i < adjacencyList[source].size(); i++)
        {
            if (has_path(adjacencyList[source].at(i), destination) == true)
            {
                return true;
            }
        }
        return false;
    }

    bool is_cyclic_recursive(string source, vector<string> elements)
    {
        for (int i = 0; i < elements.size(); i++)
        {
            if (elements.at(i) == source)
            {
                return true;
            }
        }
        elements.push_back(source);
        for (int i = 0; i < adjacencyList[source].size(); i++)
        {
            if (is_cyclic_recursive(adjacencyList[source].at(i), elements) == true)
            {
                return true;
            }
        }
        return false;
    }

    bool is_cyclic()
    {
        vector<string> elements;
        return is_cyclic_recursive(adjacencyList.begin()->first, elements);
    }
};

int main()
{
    Graph graph;
    graph.addEdge("a", "b");
    graph.addEdge("a", "c");
    graph.addEdge("b", "d");
    graph.addEdge("c", "e");
    graph.addEdge("e", "c");
    // graph.display();
    // graph.dfs();

    cout << graph.is_cyclic() << endl;
}
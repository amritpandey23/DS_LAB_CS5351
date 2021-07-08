// author: Amrit Pandey
// date: 05/07/2021
// Implement the Depth First Search (DFS) graph traversal algorithm.

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<int> *graph;
    int nodes;

public:
    Graph(int n)
    {
        this->nodes = n;
        this->graph = new vector<int>[n + 1];
    }

    bool insert(int, int);
    void dfs(int, bool *);
};

bool Graph::insert(int u, int v)
{
    if (u < 1 || v < 1 || u > nodes || v > nodes)
    {
        return false;
    }
    graph[u].push_back(v);
    graph[v].push_back(u);
    return true;
}

void Graph::dfs(int node, bool *visited)
{
    visited[node] = true;
    cout << node << " ";
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            dfs(it, visited);
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter total number of nodes : ";
    cin >> nodes;
    cout << "Enter total number of edges : ";
    cin >> edges;

    Graph g(nodes);
    cout << "Input edges in order (x,y)" << endl;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cout << "[Edge: " << i + 1 << "] : ";
        cin >> x >> y;
        if (!g.insert(x, y))
        {
            i--;
        }
    }

    cout << "Depth First Search" << endl;
    bool *visited = new bool[nodes + 1];
    for (int i = 1; i <= nodes; i++)
    {
        visited[i] = false;
    }

    int cn = 1;
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            cout << "Pair No. " << cn++ << " : ";
            g.dfs(i, visited);
            cout << endl;
        }
    }
    return 0;
}
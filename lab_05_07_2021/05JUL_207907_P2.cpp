// author: Amrit Pandey, 27907
// date: 05/07/2021
// Find minimum spanning tree of a simple connected undirected graph using Prim’s algorithm

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<pair<int, int>> *graph;
    int nodes;

public:
    Graph(int n)
    {
        this->nodes = n;
        this->graph = new vector<pair<int, int>>[n + 1];
    }
    bool insert(int, int, int);
    void prims(int, bool *, int *, int *);
};

bool Graph::insert(int x, int y, int weight)
{
    if (x < 1 || y < 1 || x > nodes || y > nodes)
    {
        return false;
    }
    graph[x].push_back({y, weight});
    graph[y].push_back({x, weight});
    return true;
}

void Graph::prims(int source, bool *mst, int *key, int *parent)
{
    key[source] = 0;
    for (int i = 1; i < nodes; i++)
    {
        int u{1}, minwt{INT_MAX};
        for (int j = 1; j <= nodes; j++)
        {
            if (minwt > key[i] && !mst[i])
            {
                minwt = key[i], u = i;
            }
        }
        if (minwt == INT_MAX)
        {
            break;
        }
        mst[u] = true;
        for (auto it : graph[u])
        {
            int v = it.first;
            int weight = it.second;
            if (!mst[v] && key[v] > weight)
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Number of nodes in graph: ";
    cin >> nodes;
    cout << "Number of edges in graph: ";
    cin >> edges;

    Graph g(nodes);
    cout << "Enter edge info in following format: (x, y, Weight), x = first node, y = second node" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        cout << "[Edge: " << i + 1 << "] : ";
        cin >> u >> v >> weight;
        if (!g.insert(u, v, weight))
        {
            i--;
        }
    }

    int source;
    cout << "Enter start/source node value: ";
    cin >> source;
    bool *mst = new bool[nodes + 1];
    int *key = new int[nodes + 1];
    int *parent = new int[nodes + 1];
    for (int i = 1; i <= nodes; i++)
    {
        mst[i] = false, key[i] = INT_MAX, parent[i] = -1;
    }
    g.prims(source, mst, key, parent);
    for (int i = 1; i <= nodes; i++)
    {
        cout << "[Node]: " << i << " - [Parent]: " << parent[i] << " - [Weight]: " << key[i] << endl;
    }
    return 0;
}
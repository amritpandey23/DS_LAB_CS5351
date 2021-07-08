// author: Amrit Pandey, 207907
// date: 05/07/2021
// Solve single source shortest problem using Bellman–Ford algorithm

#include <iostream>
#include <limits.h>
using namespace std;

struct GraphEdge
{
    int x, y, weight;
};

class Graph
{
private:
    struct GraphEdge *graph;
    int nodes;

public:
    Graph(int edges, int nodes)
    {
        this->nodes = nodes;
        this->graph = new struct GraphEdge[edges + 1];
    }
    bool insert(int, int, int, int);
    void bellmanFord(int &, int *, int &);
};

bool Graph::insert(int i, int x, int y, int weight)
{
    if (x < 1 || y < 1 || x > nodes || y > nodes)
    {
        return false;
    }
    graph[i] = {x, y, weight};
    return true;
}

void Graph::bellmanFord(int &source, int *distance, int &edges)
{
    distance[source] = 0;
    for (int n = 1; n <= nodes - 1; n++)
    {
        for (int i = 1; i <= edges; i++)
        {
            struct GraphEdge curr = graph[i];
            if (distance[curr.x] + curr.weight < distance[curr.y])
            {
                distance[curr.y] = distance[curr.x] + curr.weight;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Number of nodes in graph : ";
    cin >> n;
    cout << "Number of edges in graph : ";
    cin >> e;

    Graph g(n, e);
    cout << "Enter edges in format (x, y, weight) where x = first node, y = second node" << endl;
    for (int i = 0; i < e; i++)
    {
        int x, y, weight;
        cout << "[Edge: " << i + 1 << "] : ";
        cin >> x >> y >> weight;
        if (!g.insert(i + 1, x, y, weight))
        {
            i--;
        }
    }

    int source;
    cout << "Enter start/source node value : ";
    cin >> source;
    int *distance = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        distance[i] = INT_MAX;
    }
    g.bellmanFord(source, distance, e);
    cout << "START NODE: " << source << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance from " << i << " = ";
        if (distance[i] == INT_MAX)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << distance[i] << endl;
        }
    }
    return 0;
}
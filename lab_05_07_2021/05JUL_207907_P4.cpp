// author: Amrit Pandey, 207907
// date: 05/07/2021
// Solve single source shortest path problem using dijkstra’s algorithm and priority queue
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Graph
{
private:
    vector<pair<int, int>> *graph;
    int nodes;

public:
    Graph(int edges, int nodes)
    {
        this->nodes = nodes;
        this->graph = new vector<pair<int, int>>[nodes + 1];
    }
    bool insert(int, int, int);
    void dijkstra(int, int *);
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

void Graph::dijkstra(int source, int *dist)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for (auto it : graph[curr])
        {
            if (dist[it.first] > weight + it.second)
            {
                dist[it.first] = weight + it.second;
                cout << it.first << dist[it.first] << endl;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Number of nodes in graph : ";
    cin >> nodes;
    cout << "Number of edges in graph : ";
    cin >> edges;

    Graph g(edges, nodes);
    cout << "Enter edges info in this format: (x, y, weight) x = first node, y = second node" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        cout << "[Edge: " << i + 1 << "] : ";
        cin >> u >> v >> weight;
        if (!g.insert(u, v, weight))
            i--;
    }

    int source;
    cout << "Enter start/source node: ";
    cin >> source;
    int *distance = new int[nodes + 1];
    for (int i = 1; i <= nodes; i++)
    {
        distance[i] = INT_MAX;
    }
    g.dijkstra(source, distance);
    cout << "START NODE : " << source << endl;
    for (int i = 1; i <= nodes; i++)
    {
        cout << "distance from " << i << " = " << distance[i] << endl;
    }
    return 0;
}
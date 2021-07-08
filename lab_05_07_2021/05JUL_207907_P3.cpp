// author: Amrit Pandey, 27907
// date: 05/07/2021
// Find minimum spanning tree of a simple connected undirected graph using Kruskal’s algorithm

#include <iostream>
using namespace std;

struct GraphEdge
{
    int src, dest, weight;
};

struct subset
{
    int parent;
    int rank;
};

class Graph
{
public:
    int nodes, edges;
    GraphEdge *edge;
    Graph(int nodes, int edges)
    {
        this->nodes = nodes;
        this->edges = edges;
        this->edge = new GraphEdge[edges];
    }
};

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void _union(subset subsets[], int x, int y)
{
    int root_x = find(subsets, x);
    int root_y = find(subsets, y);

    if (subsets[root_x].rank < subsets[root_y].rank)
    {
        subsets[root_x].parent = root_y;
    }
    else if (subsets[root_x].rank > subsets[root_y].rank)
    {
        subsets[root_y].parent = root_x;
    }

    else
    {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

int compare(const void *a, const void *b)
{
    GraphEdge *a1 = (GraphEdge *)a;
    GraphEdge *b1 = (GraphEdge *)b;
    return a1->weight > b1->weight;
}

void kruskal(Graph *graph)
{
    int V = graph->nodes;
    GraphEdge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compare);
    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->edges)
    {
        GraphEdge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            _union(subsets, x, y);
        }
    }

    int mincost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        mincost = mincost + result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << mincost << endl;
}

int main()
{

    int v, e;
    cout << "Number of nodes in graph: ";
    cin >> v;
    cout << "Number of edges in graph: ";
    cin >> e;
    Graph *graph = new Graph(v, e);

    cout << "Enter edge information using following format: (x, y, weight) x = first node, y = second node" << endl;
    int x, y, w;
    for (int i = 0; i < e; i++)
    {
        cout << "[Edge " << i + 1 << "] : ";
        cin >> x >> y >> w;
        graph->edge[i].src = x;
        graph->edge[i].dest = y;
        graph->edge[i].weight = w;
    }

    kruskal(graph);

    return 0;
}

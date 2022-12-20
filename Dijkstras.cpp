#include "Dijkstras.hpp"

// Global variables
int INF = numeric_limits<int>::max();

typedef pair<int, int> apurr;

// CONSTRUCTOR
Graph::Graph(int V) // arg: number of vertices
{
    this->VERTEX_COUNT = V;
    N = new list<apurr>[V];
}


// Stores Neighbors in a List of ordered pair = (v,w). where
    // pair[0] = v: (v) is a neighbor of N[u]
    // pair[1] = w: (w) is the weight of the edge (u,v)

void Graph::addEdge(int u, int v, int w) // args: edge (u,v) , with a wieght (w)
{
    N[u].push_back(make_pair(v, w)); // Neighbors of (u) = (v,w) 
    N[v].push_back(make_pair(u, w)); // Neighbors of (v) = (u,w)
}

void Graph::shortestPath(int src, int dest)
{

    priority_queue<apurr, vector<apurr>, greater<apurr>>
        pq;

    vector<int> T(VERTEX_COUNT, INF);

    pq.push(make_pair(0, src));
    T[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i; 
        for (i = N[u].begin(); i != N[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (T[v] > T[u] + weight)
            {
                T[v] = T[u] + weight;
                pq.push(make_pair(T[v], v));
            }
        }
    }

    cout << T[dest] << endl;
}

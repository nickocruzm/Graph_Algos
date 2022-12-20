#ifndef __DIJKSTRAS_HPP__
#define __DIJKSTRAS_HPP__

#include "std_libs.hpp"

using namespace std;

// DataStructure: Adjacency List
class Graph
{
    int VERTEX_COUNT;

    list<pair<int, int>> *N; // store vertex and weight for every pair

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    void shortestPath(int s, int dest);
};


#endif
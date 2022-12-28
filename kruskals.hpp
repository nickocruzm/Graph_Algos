#ifndef __KRUSKALS_HPP__
#define __KRUSKALS_HPP__

#include "std_libs.hpp"

using namespace std;

typedef vector<int> edge;

class Graph{

public:
    vector<int> V; // vertices
    vector<edge> E; // edges


    Graph(vector<int> vertices); 

    void sort_edges();

    void add_edge(vector<int> edge);



    int find(vector<int>& P, int i);
    void Union(vector<int>& , vector<int>& , int a, int b);
    
    void kruskal();



};

#endif
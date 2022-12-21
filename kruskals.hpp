#ifndef __KRUSKALS_HPP__
#define __KRUSKALS_HPP__

#include <vector>
#include <iostream>


using namespace std;

typedef vector<int> edge;

class Graph{

public:
    vector<int> V; // vertices
    vector<edge> E; // edges
    Graph(vector<int> vertices); 

    void add_edge(vector<int> edge);

    // Search function, 
    // parent will be declared inside the kruskal method, 
    // where we call the find method.
    int find(vector<int>& parent, int i){
        if(parent[i] == i){
            return i;
        }
        return this->find(parent,parent[i]);

    }

};

#endif
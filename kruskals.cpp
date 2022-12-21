#include "kruskals.hpp"

Graph::Graph(vector<int> vertices){
    this->V = vertices;
    this->E;

}

void Graph::add_edge(vector<int> edge){
    this->E.push_back(edge);
}


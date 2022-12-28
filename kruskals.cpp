#include "kruskals.hpp"


Graph::Graph(vector<int> vertices){
    this->V = vertices;
    this->E;

}

void Graph::sort_edges(){
    for(int i = 0; i < this->E.size(); i++){
        int a = this->E[i][2];

        for(int j = i+1; j < this->E.size(); j++){
            int b = this->E[j][2];

            if(b < a){
                edge tmp = this->E[j];
                this->E[j] = this->E[i];
                this->E[i] = tmp;

            }
            break;
        }
    }
}

void Graph::add_edge(vector<int> edge){
    this->E.push_back(edge);
}

// Search function, 
// parent[] will be declared inside the kruskal method, 
// where we call the find method.
int Graph::find(vector<int>& P, int i){
    if(P[i] == i){
        return i;
    }
    return this->find(P,P[i]);
}

// rank[] will be declared inside the kruskal method
void Graph::Union(vector<int>& P, vector<int>& rank, int a, int b){
    int a_root = this->find(P,a);
    int b_root = this->find(P,b);

    if(rank[a_root] < rank[b_root]){
        P[a_root] = b_root;
    }
    else if(rank[a_root] > rank[b_root]){
        P[b_root] = a_root;
    }
    else{
        P[b_root] = a_root;
        rank[a_root] = rank[a_root] + 1;
    }

}

void Graph::kruskal(){
    vector<edge> result;

    vector<int> P;
    vector<int> rank;

    for(int i = 0; i < this->V.size();i++){
        P.push_back(i);
        rank.push_back(0);
    }
    
    int e = 0;
    int k = 0;


    this->sort_edges();

    while(e < this->V.size()){
        edge temp_edge = this->E[e];

        int x = this->find(P,temp_edge[0]);
        int y = this->find(P,temp_edge[1]);

        if (x != y){
            e = e + 1;
            result.push_back(temp_edge);
            this->Union(P,rank,x,y);
        }

        for(int q = 0; q < result.size(); q++){
            cout << this->E[q][0] << this->E[q][1] << this->E[q][2]<<endl;
        }

    }



}


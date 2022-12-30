#include "BellmanFord.hpp"

int BellmanFord(Graph& G, int s, int f){
    int N = G.v_count();
    int M = G.e_count();
    vector<int> T_dist(N,inf);
    // if(f<s){
    //     int t = s;
    //     s = f;
    //     f = t;

    // }
    T_dist[s] = 0;

    int su = s;
    for(int i = 0; i < N; i++){
        int ui = G.E[i].u;
        int vi = G.E[i].v;

        if(su != ui){
            continue;
        }

        else{ 
            T_dist[vi] = T_dist[ui] + G.E[i].w;
        }


    }


    cout<< endl;
    for(int i = 0; i < T_dist.size(); i++){
        cout<< "i: "<<i << " "<< T_dist[i] << endl;
    }

    for(int i = 0; i < N; i++){
        cout<<"i: "<< i << endl;
        cout<<"\t"<< endl;

        
        for(int j = 0; j < M; j++){
            int bu = G.E[j].u;
            int bv = G.E[j].v;
            int bw = G.E[j].w;
            G.E[j].dprint();
            cout<< endl;
            cout<< "T[u]: "<< T_dist[bu]<< ", "<< "T[v]: "<< T_dist[bv] << endl;

            if(T_dist[bu] != inf && T_dist[bu] + bw <= T_dist[bv]){
                T_dist[bv] = T_dist[bu] + bw;
            }



        }

        // for (int i = 0; i < G.e_count(); i++) {
        //     int bu = G.E[i].u;
        //     int bv = G.E[i].v;
        //     int weight = G.E[i].w;
        //     if (T_dist[bu] != inf
        //         && T_dist[bu] + weight < T_dist[bv]) {
        //     }
 
        // }
    }
    cout<< endl;
    for(int i = 0; i < T_dist.size(); i++){
        cout<< "i: "<<i << " "<< T_dist[i] << endl;
    }

}

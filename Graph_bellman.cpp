#include<bits/stdc++.h>
using namespace std;

void bellman(int V,vector<vector<int>> &edges,int src){
    vector<int> source(V,INT_MAX);
    source[src]=0;
    for(int i=1;i<=V-1;i++){
        for(auto &e:edges){
            int u=e[1],v=e[2],w=e[0];
            if(source[u] != INT_MAX && source[u]+w<source[v]){
                source[v]=source[u]+w;
            }
        }
    }
    for(auto &e:edges){
        int u=e[1],v=e[2],w=e[0];
        if(source[u] != INT_MAX && source[u]+w<source[v]){
            cout<<"Negative Cycle Detected"<<endl;
        }
    }
    for(int i = 0; i < V; i++) {
        cout << "Distance to " << i << " = " << source[i] << "\n";
    }
}
int main(){
    int V=3;
    vector<vector<int>> edges={
        {1, 0, 1},   // 0 -> 1 (1)
        {-1, 1, 2},  // 1 -> 2 (-1)
        {-1, 2, 0}
        // {4, 0, 1},
        // {4, 0, 2},
        // {-2, 1, 2},
        // {-5, 1, 3},
        // {-5, 2, 3},
        // {6, 2, 4},
        // {3, 3, 4}
    };
    int src;
    cin>>src;
    bellman(V,edges,src);
}
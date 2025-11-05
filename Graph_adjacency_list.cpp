#include<bits/stdc++.h>
using namespace std;

class Graph{
public :
    int V;
    vector<vector<int>> adj;
    Graph(int vertices){
        V=vertices;
        adj.resize(vertices);
    }
    void addedge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int a: adj[i]){
                cout<<a<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.print();
}
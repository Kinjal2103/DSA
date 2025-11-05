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
    void DFS(int start){
        vector<int> visited(V);
        stack<int> q;
        visited[start]=1;
        q.push(start);
        while(!q.empty()){
            int node =q.top();
            q.pop();
            cout<<node<<" ";
            for(int a: adj[node]){
                if(!visited[a]){
                    visited[a]=1;
                    q.push(a);
                }
            }
        }
        cout<<endl;
    }
    

};

int main(){
    int n,m;
    //cin>>n>>m;
    n=4;
    Graph g(n);
    // for(int i=0;i<n;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.addedge(u,v);
    // }
    g.addedge(0,1);
    g.addedge(2,3);
    g.addedge(0,3);
    g.addedge(1,2);
    g.DFS(0);
}
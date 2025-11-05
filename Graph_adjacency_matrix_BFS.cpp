#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> adj;
public:
    Graph(int n){
        adj=vector<vector<int>> (n,vector<int>(n,0));
    }
    void addedge(int u,int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void BFS(int start){
        int V=adj.size();
        vector<int> visited(V);
        queue<int> q;
        visited[start]=1;
        q.push(start);
        while(!q.empty()){
            int node =q.front();
            q.pop();
            cout<<node<<" ";
            for(int a=0;a<V;a++){
                if(adj[node][a] && !visited[a]){
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
    g.BFS(0);
    
}
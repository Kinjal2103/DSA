#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>dist(n+1,INT_MAX),parent(n+1,-1);
    queue<int>q;
    
    int S,D;
    cin>>S>>D;
    dist[S]=0;
    q.push(S);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]==INT_MAX){
                dist[v]=dist[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
    if(dist[D]==INT_MAX){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<dist[D]<<endl;
    vector<int>path;

    for(int i=D;i!=-1;i=parent[i]){
        path.push_back(i);
    }
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<endl;

}

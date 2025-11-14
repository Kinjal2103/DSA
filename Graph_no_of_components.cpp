#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj,vector<int> &visited ){
    visited[i]=1;
    for(int v: adj[i]){
        if(!visited[v])
            dfs(v,adj,visited);
    }
}
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
    int ans=0;
    vector<int>visited (n+1);
    for(int i=1;i<=n ;i++){
        if(!visited[i]){
            ans++;
            dfs(i,adj,visited);
        }
    }
    cout<<ans<<endl;
}
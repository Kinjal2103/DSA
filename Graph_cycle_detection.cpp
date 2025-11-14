#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, int parent,vector<vector<int>> &adj,vector<int> &visited ){
    visited[i]=1;
    for(int v: adj[i]){
        if(!visited[v]) {
            if(dfs(v,i,adj,visited)) return true;
        }
        else if(v!=parent) return true;
    }
    return false;
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
    
    vector<int>visited (n+1);
    for(int i=1;i<=n ;i++){
        if(!visited[i]){
            if(dfs(i,-1,adj,visited)){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}
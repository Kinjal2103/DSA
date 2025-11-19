#include<bits/stdc++.h>
using namespace std;
void prims(int V,vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> adj(V); 

    for(auto &e : edges) {
        int w = e[0];
        int u = e[1];
        int v = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> key(V, INT_MAX);      
    vector<int> visited(V);       
    vector<int> parent(V, -1);

    key[0]=0;
    priority_queue<pair<int,int>,
        vector<pair<int,int>>, 
        greater<pair<int,int>>
    > pq;
    pq.push({0,0});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=1;
        for(auto &p: adj[u]){
            int v=p.first;
            int w=p.second;
            if(!visited[v] && w<key[v]){
                key[v]=w;
                parent[v]=u;
                pq.push({w,v});
            }
        }
    }
    int totalWeight = 0;
    for(int i = 1; i < V; i++) {
        totalWeight += key[i];
    }
    cout << totalWeight << endl;

    cout<<"The paths are"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" -> "<<i<<" = "<<key[i]<<endl;
    }
}

int main(){
    int V=5;
    vector<vector<int>> edges={
        {4, 0, 1},
        {4, 0, 2},  
        {2, 1, 2},
        {5, 1, 3},
        {5, 2, 3},
        {6, 2, 4},
        {3, 3, 4}
    };
    prims(V,edges);
}
#include<bits/stdc++.h>
using namespace std;
void dijkstra(int V, vector<vector<int>> &edges, int src){
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e : edges) {
        int w = e[0];
        int u = e[1];
        int v = e[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int u=it.second;
        for(auto &e:adj[u]){
            int v = e.first;
            int w = e.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v]=u;
            }
        }
    }
    for(int i = 0; i < V; i++){
        cout << "Distance to " << i << " = " << dist[i] << "\n";
    }
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX){
            cout<<"NO PATH"<<endl; 
            continue;
        }
        vector<int>path;
        int node=i;
        while(node!=-1){
            path.push_back(node);
            node=parent[node];
        }
        for(int i=path.size()-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
        cout<<endl;
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
    int src;
    cin >> src;

    dijkstra(V, edges, src);
}
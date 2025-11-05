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
    void print(){
        cout << "Adjacency Matrix for the Graph: " << endl;
        int n = adj.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

};
int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.print();
    
}
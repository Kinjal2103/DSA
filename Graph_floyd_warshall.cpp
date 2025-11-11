#include<bits/stdc++.h>
using namespace std;

void printPath(vector<vector<int>> &next,int u,int v){
    if(u==v){
        cout<<u<<" ";
    }else{
        if(next[u][v]==-1) cout<<"No path exist ";
        else{
            printPath(next,u,next[u][v]);
            cout<<v<<" ";
        }
    }


}
int main(){
    int V=6;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 3, 7},
        {1, 0, 8},
        {1, 2, 2},
        {2, 0, 5},
        {2, 3, 1},
        {3, 0, 2}
    };

    vector<vector<int>> dist(V,vector<int>(V,INT_MAX));
    vector<vector<int>> next(V,vector<int>(V,-1));
    
    for(int i=0;i<V;i++){
            dist[i][i]=0;
    }
    for(auto &e : edges){
        int u=e[0],v=e[1],w=e[2];
        dist[u][v]=w;
        next[u][v]=u;
    }
    for(int k=0;k< V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]<INT_MAX && dist[k][j]<INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    next[i][j]=next[k][j];
                }
            }
        }
    }

    printPath(next,0,2);
    cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x,int y){
        x=find(x);
        y=find(y);

        if(x!=y){
            if(rank[x]>rank[y]){
                parent[y]=x;
            }else if(rank[x]<rank[y]){
                parent[x]=y;
            }else{
                parent[y]=x;
                rank[x]++;
            }
        }
    }
};
int main(){
    int V=6;
    vector<vector<int>> edges={
        {4, 0, 1},
        {4, 0, 2},
        {2, 1, 2},
        {5, 1, 3},
        {5, 2, 3},
        {6, 2, 4},
        {3, 3, 4}
    };
    sort(edges.begin(),edges.end());
    DSU dsu(V);
    int total_weight=0;

    for(auto it: edges){
        int w=it[0],u=it[1],v=it[2];
        if(dsu.find(u)!=dsu.find(v)){
            dsu.unionSet(u,v);
            total_weight+=w;
        }
    }
    cout<<total_weight<<endl;
}
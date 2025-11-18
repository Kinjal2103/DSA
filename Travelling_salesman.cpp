#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj={
        {0, 10 ,15, 20},
        {10 ,0 ,35, 25},
        {15, 35, 0 ,30},
        {20 ,25 ,30 ,0}
    };
    int n=adj.size();
    vector<int>visited(n,0);

    int total=0;
    vector<int>path;

    int start=0;
    visited[start]=1;
    path.push_back(start);
    int curr=start;

    for(int k=1;k<n;k++){
        int next=-1;
        int minD=INT_MAX;
        for(int j=0;j<n;j++){
            if(!visited[j] && adj[curr][j]<minD){
                minD=adj[curr][j];
                next=j;
            }
        }
        visited[next]=1;
        path.push_back(next);
        total+=adj[curr][next];
        curr=next;
        
    }
    total += adj[curr][start];
    cout << "TSP Greedy Path: ";
    for(int x : path) cout << x << " ";
    cout << "\nTotal Cost: " << total << endl;
}
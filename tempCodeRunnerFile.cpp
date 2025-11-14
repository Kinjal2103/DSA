include<bits/stdc++.h>
using namespace std;

bool bfs(int i,vector<vector<int>> & adj,vector<int> &color){
    queue<int>q;
    q.push(i);
    color[i]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v: adj[u]){
            if(color[v]!=-1){
                color[v]=1-color[u];
                q.push(u);
            }
            else if(color[u]==color[v]){
                return false;
            }
        }
    }
    return true;
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

    vector<int> color(n+1);

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bfs(i,adj,color)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}
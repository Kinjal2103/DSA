#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int k;
    cin>>k;
    pair<int,int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==k){
                ans.first=i;
                ans.second=j;
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}
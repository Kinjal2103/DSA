#include<bits/stdc++.h>
using namespace std;
void printOptimal(vector<vector<int>> &sp,int i ,int j){
    if(i==j) cout<<"A"<<i;
    else{ cout<<"(";
        printOptimal(sp,i,sp[i][j]);
        printOptimal(sp,sp[i][j]+1,j);
        cout<<")";
    }
}
int matrixchainorder(vector<int> &p){
    int n=p.size()-1;
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    vector<vector<int>>sp(n+1,vector<int>(n+1));
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int cost=dp[i][k]+dp[k+1][j] +p[i-1]*p[k]*p[j];
                if(dp[i][j]>cost){
                    dp[i][j]=cost;
                    sp[i][j]=k;
                }
            }
        }
    }
    printOptimal(sp,1,n);
    cout<<endl;
    return dp[1][n];
}
int main(){
    vector<int> p={30,35,15,5,10,20,25};
    cout<<matrixchainorder(p)<<endl;
}
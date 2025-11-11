#include<bits/stdc++.h>
using namespace std;

int isSafe(int row,int col,vector<string> &board,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q') return 0;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return 0;
    }
    for(int i=row-1,j=col+1;i>=0 && j<n; i--, j++)
        if(board[i][j]=='Q') return 0;
    return 1;
}
void solve(int row,vector<string> &board,int n,vector<vector<string>> &ans){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(row+1,board,n,ans);
            board[row][col]='.';
        }
    }

}
int main(){
    int n;
    cin>>n;
    
    vector<vector<string>> ans;
    vector<string> board(n,string(n,'.'));

    solve(0,board,n,ans);

    cout << "Total Solutions: " << ans.size() << endl;
    for(auto &config : ans) {
        for(auto &row : config)
            cout << row << endl;
        cout << endl;
    }
}
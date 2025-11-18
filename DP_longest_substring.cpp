#include<bits/stdc++.h>
using namespace std;
void printLCS(vector<vector<char>> &b ,string x,int i,int j){
    if(i==0 || j==0) return;
    if(b[i][j]=='d'){
        printLCS(b,x,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(b[i][j]=='u'){
        printLCS(b,x,i-1,j);
    }
    else printLCS(b,x,i,j-1);
}
void LCS(string x,string y){
    
    int m=x.length();
    int n=y.length();
    vector<vector<int>> c(m+1,vector<int>(n+1));
    vector<vector<char>> b(m+1,vector<char>(n+1));

    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i][j-1]>c[i-1][j]){
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
            else{
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
        }
    }
    printLCS(b,x,m,n);
    cout<<endl;

}
int main(){
    string x="ABCBDAB";
    string y="BDCABA";
    LCS(x,y);
}
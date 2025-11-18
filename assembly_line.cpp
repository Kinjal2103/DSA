#include<bits/stdc++.h>
using namespace std;
void printPath(vector<int> l1,vector<int> l2 ,int i,int n){
    cout << "Line " << i + 1 << ", Station " << n << endl;
    for(int j=n;j>=2;j--){
        if(i==0){
            i=l1[j];
        }
        else i=l2[j];
        cout << "Line " << i + 1 << ", Station " << j - 1 << endl;
    }
}
void assemblyLine(vector<vector<int>> &a,vector<vector<int>>&t, vector<int> &e,vector<int> &x){
    int n=a[0].size();
    vector<int> F1(n),F2(n);
    vector<int> l1(n+1),l2(n+1);

    F1[0]=e[0]+a[0][0];
    F2[0]=e[1]+a[1][0];

    for(int i=1;i<n;i++){
        int b=F1[i-1]+a[0][i];
        int c=F2[i-1]+t[1][i-1]+a[0][i];
        if(b<c){
            F1[i]=b;
            l1[i+1]=0;
        }
        else{
            F1[i]=c;
            l1[i+1]=1;
        }

        b=F2[i-1]+a[1][i];
        c=F1[i-1]+t[0][i-1]+a[0][i];
        if(b<c){
            F2[i]=b;
            l2[i+1]=1;
        }
        else{
            F2[i]=c;
            l2[i+1]=0;
        }
        
        
    }
    int final,lastline;
    if(F1[n-1]+x[0]<=F2[n-1]+x[1]){
            final=F1[n-1]+x[0];
            lastline=0;
    }
    else{
            final=F2[n-1]+x[1];
            lastline=1;
    }
    cout << "Minimum Cost: " << final << endl;
    cout << "Optimal Path (Reverse Order):" << endl;
    printPath(l1, l2, lastline, n);
}
int main(){
    vector<vector<int>> a = {{7, 9, 3, 4, 8, 4}, 
                             {8, 5, 6, 4, 5, 7}};
    
    vector<vector<int>> t = {{2, 3, 1, 3, 4}, 
                             {2, 1, 2, 2, 1}};
    
    vector<int> e = {2, 4}; 
    vector<int> x = {3, 2}; 

    assemblyLine(a, t, e, x);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int jumpSearch(vector<int>&a,int x){
    int n=a.size();
    int step=sqrt(n);
    int prev=0;

    while(a[min(step,n)-1]<x){
        prev=step;
        step+= sqrt(n);
        if(prev>=n) return -1;
    }
    for(int i=prev;i<min(step,n);i++){
        if(a[i]==x) return i;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int ans=jumpSearch(a,x);
    cout<<ans<<endl;
}

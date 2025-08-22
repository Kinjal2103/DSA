#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&a,int t,int st,int end){
    if(st<=end){
        int mid=st+(end-st)/2;
        if(t>a[mid]){
            return binarySearch(a,t,mid+1,end);
        }
        else if(t<a[mid]){
            return binarySearch(a,t,st,mid-1);
        }
        else{
            return mid;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t;
    cin>>t;
    int ans=binarySearch(a,t,0,n-1);
    cout<<ans+1<<endl;
}
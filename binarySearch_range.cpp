#include<bits/stdc++.h>
using namespace std;

int first(vector<int>&a,int n,int k){
    int start=0,end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==k){
            ans=mid;
            end=mid-1;
        }else if(a[mid]<k){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int last(vector<int>&a,int n,int k){
    int start=0,end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==k){
            ans=mid;
            start=mid+1;
        }else if(a[mid]<k){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k;
        cin>>k;
        int f=first(a,n,k);
        int l=last(a,n,k);
        cout<<f<<" "<<l<<endl;
    }
}

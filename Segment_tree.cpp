#include<bits/stdc++.h>
using namespace std;

vector<int> a(100000) ,seg(1000000);
void build(int i,int low,int high){
    if(low==high){
        seg[i]=a[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(2*i+1,low,mid);
    build(2*i+2,mid+1,high);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}

int query(int i,int low,int high, int l,int r){
    if(low>=l && high<=r){
        return seg[i];
    }if(high<l || low>r){
        return 0;
    }
    int mid=(high+low)/2;
    int left=query(2*i+1,low,mid,l,r);
    int right=query(2*i+2,mid+1,high,l,r);
    return left+right;

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l,r;
    cin>>l>>r;
    build(0,0,n-1);
    int ans=query(0,0,n-1,l,r);
    cout<<ans<<endl;
}
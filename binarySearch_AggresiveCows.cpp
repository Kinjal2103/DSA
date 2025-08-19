// https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;
int canPlace(vector<int>& a,int c,int mid,int n){
    int count=1;
    int p=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-p>=mid){
            count++;
            p=a[i];
            if(count==c) return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());

        int l=1,r=a[n-1]-a[0];
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canPlace(a,c,mid,n)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}
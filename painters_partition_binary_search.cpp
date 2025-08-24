//https://www.youtube.com/watch?v=srsFN5OHBgw&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=22
#include<bits/stdc++.h>
using namespace std;
int isValid(vector<int>a,int mid,int n,int m){
    int st=1,sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid) return 0;
        if(sum+a[i]<=mid){
            sum+=a[i];
        }else{
            st++;
            sum=a[i];
        }
    }
    if(st<=m) return 1;
    else return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int st=*max_element(a.begin(),a.end());
    if(m>n) cout<<-1<<endl;
    int ans=-1;
    int end=sum;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(a,mid,n,m)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    cout<<ans<<endl;
}
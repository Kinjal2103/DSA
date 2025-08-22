#include<bits/stdc++.h>
using namespace std;
int jumpSearch(vector<int>&a,int k,int t){
    int ans=1;
    int step=0;
    int n=a.size();
    if(a[0]==t) return ans;
    while(step+k<n && a[step+k]<t){
        ans++;
        step+=k;
    }
    if(step+k<n){
        step+=k;
        ans++;

        int prev=step-k;
        for(int i=step;i>=prev;i--){
            if(i!=step)ans++;
            if(a[i]==t) return ans;
        }
    }else{
        int start=step;
        for(int i=start;i<n;i++){
            if(i!=start)ans++;
            if(a[i]==t) return ans;
        }
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t;
    cin>>t;
    int ans=jumpSearch(a,k,t);
    cout<<ans<<endl;
}
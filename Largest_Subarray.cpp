#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int>mp;
    int prefixSum=0;
    mp[prefixSum]=-1;
    int ans=0;
    for(int i=0;i<n;i++){
        prefixSum+=nums[i];
        int req=prefixSum;
        if(mp.find(req)!=mp.end()){
            ans=max(ans,i-mp[req]);
        }
        else{
            mp[prefixSum]=i;
        }
    }
    cout<<ans<<endl;

}
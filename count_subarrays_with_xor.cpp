#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int>mp;
    int prefixXor=0;
    mp[prefixXor]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        prefixXor^=nums[i];
        int req=prefixXor^target;
        if(mp.find(req)!=mp.end()){
            ans+=mp[req];
        }
        mp[prefixXor]++;
    }
    cout<<ans<<endl;

}
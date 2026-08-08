#include <bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        vector<int>v;
        vector<int>temp;
        int ans=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++){
            if(curr+nums[i]>=nums[i]){
                curr+=nums[i];
                temp.push_back(nums[i]);
            }else{
                curr=nums[i];
                temp={nums[i]};
            }

            if(curr>ans){
                v=temp;
                ans=curr;
            }
        }

        for(int x:v){
            cout<<x<<" ";
        }
}

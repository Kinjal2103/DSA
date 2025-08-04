//https://leetcode.com/problems/majority-element/description/
//Brute force - find frequency 
//Optimal -Sorting (then find frequency)
// mY SOLUTION
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0) ans=nums[i];
            if(ans==nums[i]) freq++;
            else freq--; 
        }
        return ans;
    }
};

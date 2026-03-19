#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sub(vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums,int ind){
        if(ind==0){
           ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind-1]);
        sub(ans,curr,nums,ind-1);
        curr.pop_back();
        sub(ans,curr,nums,ind-1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
        vector<int>curr;
        int index = nums.size();
        sub(ans,curr,nums,index);
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void lol(vector<vector<int>>&v, vector<int>&curr,vector<bool>&vis,vector<int>&nums){
        int n =nums.size() ;       if(curr.size()==nums.size()){
            v.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                curr.push_back(nums[i]);
                vis[i]=true;
                lol(v,curr,vis,nums);
                 vis[i]=false;
                curr.pop_back();
                
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        vector<vector<int>>v;
        vector<bool>vis(n,false);
        lol(v,curr,vis,nums);
        return v;
        
    }
};
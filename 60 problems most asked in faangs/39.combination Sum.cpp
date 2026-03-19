#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void lol(vector<vector<int>>&v,vector<int>&curr,int target,vector<int>&candidates,int i){
        if(i==0 && target==0){
            v.push_back(curr);
            return;
        }
        if(target<0 || i<=0)return;
        curr.push_back(candidates[i-1]);
        lol(v,curr,target-candidates[i-1],candidates,i);
        curr.pop_back();
        lol(v,curr,target,candidates,i-1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>curr;
        int i=candidates.size();
        lol(v,curr,target,candidates,i);
        return v;
    }
};
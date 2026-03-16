#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
            set<pair<int,int>>s;
            while(k!=j){
                int sum = nums[j]+nums[k]+nums[i];
                if(sum==0 && s.find({nums[j],nums[k]})==s.end()){
                    v.push_back({nums[i],nums[j],nums[k]});
                    s.insert({nums[j],nums[k]});
                    j++;
                    
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i!=nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }

        }
        return v;
    }
};

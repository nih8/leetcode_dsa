#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int curr = target-nums[i];
            if(m.count(curr)){
                if(m[curr]!=i){
                    return {m[curr],i};
                }
            }
        }
        return {};
        
    }
};
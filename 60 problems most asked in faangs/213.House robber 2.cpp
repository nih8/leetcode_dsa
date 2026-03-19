#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0]; 
        vector<int>dp(n-1,0);
        vector<int>dp2(n-1,0);
        dp[0] = nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        int max1 = dp[n-2];
        dp2[0] = nums[1];
        dp2[1] = max(nums[1],nums[2]);
        for(int i=2;i<n-1;i++){
            dp2[i] = max(dp2[i-1],dp2[i-2] + nums[i+1]);
        }
        int max2 = dp2[n-2];
        return max(max2,max1);
    }
};
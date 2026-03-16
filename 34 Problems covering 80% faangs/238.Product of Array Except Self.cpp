#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,1);
        vector<int>suf(n,1);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
            suf[n-1-i]=suf[n-i]*nums[n-i];
        }
        
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i] = pre[i]*suf[i];
        }
        return v;
    }
};
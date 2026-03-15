#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pre(height.size(),0);
        pre[0]=height[0];
        
        vector<int>suf(height.size(),0);
        suf.back()=height.back();
        int n = height.size();
        for(int i=1;i<height.size();i++){
            if(height[i]>pre[i-1]) pre[i] = height[i];
            else pre[i] = pre[i-1];

            if(height[n-i-1]>suf[n-i]) suf[n-i-1] = height[n-i-1];
            else suf[n-i-1] = suf[n-i];
        }
        int water =0;
        for(int i=0;i<n;i++){
            water += (min(pre[i],suf[i]) - height[i]);
        }
        return water;

    }
};
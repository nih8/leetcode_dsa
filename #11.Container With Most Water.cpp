#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int maxx=0;
        while(i<j){
            int width = j-i;
            int length = min(height[i],height[j]);
            maxx = max(length*width,maxx);
            if(height[i]<=height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxx;
    }
};
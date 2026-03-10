#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            else return -1;
        }
        int l=0;
        int r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target==nums[m]){
                return m;
            }
            if(nums[l] <= nums[m]){ 
                if(target>=nums[l] && target<nums[m])
                    r=m-1;
                else
                    l=m+1;
            }
            else{
                if(target>nums[m] && target<=nums[r])
                    l=m+1;
                else
                    r=m-1;
            }
        }
        return -1;
        
    }
};
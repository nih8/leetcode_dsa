#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxx=0;
        /*unordered_set<int>s;
        for(int num:nums){
            s.insert(num);
        }
        for(int num:s){
            if(s.find(num-1)==s.end()){
            int curr = 1;
            while(s.find(num+1)!=s.end()){
                num++;
                curr++;
            }
            maxx = max(maxx,curr);}
        }*/
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int lol =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                lol++;
            }
            else if(nums[i]==nums[i-1])continue;
            else{
                maxx = max(maxx,lol);
                lol=1;
            }
        }
        maxx = max(maxx,lol);
        return maxx;
    }
};
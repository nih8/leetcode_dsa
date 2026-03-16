#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>s;
        bool flag = false;
        for(int num:nums){
            if(s.empty() || num>0 || (num<0 && s.top()<0))s.push(num);
            else{while(!s.empty()&& s.top()>0 && num<0){
                int lol = s.top();
                s.pop();
                if(lol+num==0){
                    flag = true;
                    break;
                    
                }
                else{
                    num = lol>abs(num)? lol:num;
                    
                }
                
            }
            if(!flag){
            s.push(num);}
            if(flag)flag = false;
            }
        }
        vector<int>ans;
        while(!s.empty()){
            int curr = s.top();
            ans.push_back(curr);
            s.pop();
        }
        vector<int>final(ans.rbegin(),ans.rend());
        return final;
    }
};
#include<bits/stdc++.h>
using namespace std;

//very weird intuition but code ez
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pos(n,n);
        vector<int>pre(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                pos[i] = s.top();
            }
            s.push(i);
        }
        stack<int>s2;
        for(int i=0;i<n;i++){
            while(!s2.empty() && heights[s2.top()]>=heights[i]){
                s2.pop();
            }
            if(!s2.empty()){
                pre[i] = s2.top();
            }
            s2.push(i);
        }
        int maxx=0;
        for(int i=0;i<n;i++){
           
            maxx = max(maxx,(pos[i]-pre[i]-1)*heights[i]);
        }
        return maxx;
    }
};
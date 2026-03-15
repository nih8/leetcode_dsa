#include<bits/stdc++.h>
using namespace std;
//2 approaches, one by sorting and one using priority queue
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<intervals.size();i++){
            pq.push({intervals[i][0],intervals[i][1]});
        }
        int start=pq.top().first;
        int end = pq.top().second;
        pq.pop();
        vector<vector<int>>ans;
        while(!pq.empty()){
            int curr_start = pq.top().first;
            int curr_end = pq.top().second;
            pq.pop();
            if(curr_start>=start && curr_start<=end){
                end = max(curr_end,end);
            }
            else{
                ans.push_back({start,end});
                start = curr_start;
                end = curr_end;
            }
        }
        ans.push_back({start,end});
        return ans;*/
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=start && intervals[i][0]<=end){
                end = max(intervals[i][1],end);
            }
            else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
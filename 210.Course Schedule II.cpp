#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numcourses, vector<vector<int>>& prereq) {
        vector<vector<int>>graph(numcourses);
        vector<int>indegree(numcourses,0);
        for(auto edge : prereq){
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        vector<int>order;
        queue<int>q;
        for(int i=0;i<numcourses;i++){
            if(!indegree[i]){
                q.push(i);
                order.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neigh:graph[curr]){
                indegree[neigh]--;
                if(!indegree[neigh]){
                    q.push(neigh);
                    order.push_back(neigh);
                }
            }
        }
        if(order.size()==numcourses){
            return order;
        }
        else return {};
    }
};
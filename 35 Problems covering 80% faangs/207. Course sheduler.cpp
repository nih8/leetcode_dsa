#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numcourses);
        vector<int>indegree(numcourses,0);
        for(auto lol:prerequisites){
            graph[lol[1]].push_back(lol[0]);
            indegree[lol[0]]++;
        }
        int count =0;
        queue<int>q;
        for(int i=0;i<numcourses;i++){
            if(!indegree[i]){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neigh : graph[curr]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                    count++;
                }
            }
        }
        return count==numcourses;

    }
};
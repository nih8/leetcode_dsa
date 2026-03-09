#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
       
        int maxx=0;
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']++;
            
            maxx = max(maxx,v[tasks[i]-'A']);
        }
        
        maxx = maxx-1;
        //there will be maxx-1 gaps after placing the highest freq alphabet, therfore maxx-1 times n idle states
        int idle = (maxx*n) + maxx;
        for(int i=0;i<26;i++){
            idle -= min(maxx,v[i]);
        }
        
        return idle>0? idle+tasks.size():tasks.size();




        
    }
};
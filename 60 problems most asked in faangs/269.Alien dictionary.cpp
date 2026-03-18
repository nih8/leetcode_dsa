#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bfs(vector<vector<int>>v,int start,int end){
        vector<int>dist(v.size(),1e9);
        dist[start]=0;
        
        if(start==end)return 0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int curr = q.front();q.pop();
            for(int child:v[curr]){
                if(dist[child]>dist[curr]+1){
                    dist[child]=dist[curr]+1;
                    q.push(child);
                }
            }
        }
        
        return dist[end];
    }
    bool check(string a, string b){
        int count =0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                count++;
            }
            if(count==2)return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>>v(n);
        int begin=-1;
        int end=-1;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord)begin = i;
            if(wordList[i]==endWord)end = i;
            for(int j=i+1;j<n;j++){
                if(check(wordList[i],wordList[j])){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        if(end==-1)return 0;
        int dist=INT_MAX;
        if(begin==-1){
            cout<<"yess"<<endl;
            for(int i=0;i<n;i++){
                if(check(beginWord,wordList[i])){
                    int lol = bfs(v,i,end) +1;
                    dist = min(dist,lol);
                }

            }
            if(dist>=1e9)return 0;
            else return dist+1;
        }
        else{
            if(bfs(v,begin,end)>=1e9)return 0;
            else return bfs(v,begin,end)+1;
        }

    }
};
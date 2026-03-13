#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<bool>>&visited,vector<vector<int>>& heights,int i,int j,int n,int m){
        visited[i][j]=true;
        if(i!=0 && !visited[i-1][j] && heights[i-1][j]>=heights[i][j]){
            dfs(visited,heights,i-1,j,n,m);
        }
        if(i!=n-1 && !visited[i+1][j] && heights[i+1][j]>=heights[i][j]){
            dfs(visited,heights,i+1,j,n,m);
        }
        if(j!=0 && !visited[i][j-1] && heights[i][j-1]>=heights[i][j]){
            dfs(visited,heights,i,j-1,n,m);
        }
        if(j!=m-1 && !visited[i][j+1] && heights[i][j+1]>=heights[i][j]){
            dfs(visited,heights,i,j+1,n,m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(pac,heights,i,0,n,m);
            dfs(atl,heights,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            dfs(pac,heights,0,j,n,m);
            dfs(atl,heights,n-1,j,n,m);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
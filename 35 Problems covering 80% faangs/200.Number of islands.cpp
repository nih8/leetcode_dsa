#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&visited,int n,int m){
        visited[i][j]=true;
        if(i!=n-1 && grid[i+1][j]=='1' && !visited[i+1][j]){
            dfs(grid,i+1,j,visited,n,m);
        }
        if(i!=0 && grid[i-1][j]=='1' && !visited[i-1][j]){
            dfs(grid,i-1,j,visited,n,m);
        }
        if(j!=m-1 && grid[i][j+1]=='1' && !visited[i][j+1]){
            dfs(grid,i,j+1,visited,n,m);
        }
        if(j!=0 && grid[i][j-1]=='1' && !visited[i][j-1]){
            dfs(grid,i,j-1,visited,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,i,j,visited,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};
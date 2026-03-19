#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lol(vector<vector<char>>& board, string word,int i,int j,int k,int n,int m,vector<vector<bool>>&vis){
         if(board[i][j]!=word[k])return false;
        if(k==word.size()-1)return true;
       
        vis[i][j]=true;
        bool ok1=false,ok2=false,ok3=false,ok4=false;
        if(i!=n-1 && !vis[i+1][j]){
            ok1=lol(board,word,i+1,j,k+1,n,m,vis);
        }
        if(j!=m-1 && !vis[i][j+1] ){
            ok2=lol(board,word,i,j+1,k+1,n,m,vis);
        }
        if(i!=0 && !vis[i-1][j]){
            ok3=lol(board,word,i-1,j,k+1,n,m,vis);
        }
        if(j!=0 && !vis[i][j-1]){
            ok4=lol(board,word,i,j-1,k+1,n,m,vis);
        }
        vis[i][j]=false;
        return ok1||ok2||ok3||ok4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>>vis(n,vector<bool>(m,false));
                    
                   if(lol(board,word,i,j,0,n,m,vis))return true;
                }
            }
        }
        return false;
    }
};
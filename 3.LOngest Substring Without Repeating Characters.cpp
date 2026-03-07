#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>m;
       if(s.size()==1){
        return 1;
       }
       int maxx=0;
       int j=0;
       int i;
       for(i=0;i<s.size();i++){
        if(m.count(s[i])){
            maxx = max(maxx,i-j);
           
            j = max(m[s[i]]+1,j); //becauseeeee the window should only move forward not backward
            
        }
        m[s[i]]=i;

       }
       int lol = s.size();
       maxx = max(maxx,lol-j);
       return maxx;
    }
};
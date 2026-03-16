#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>pmap; //can use a vector
        for(char c:p){
            pmap[c]++;
        }
        int psize = p.size();
        unordered_map<char,int>smap;
        for(int i=0;i<psize;i++){
            smap[s[i]]++;
        }
        int lol =0;
        vector<int>ans;
        for(int i=psize;i<s.size();i++){
            if(smap==pmap){
                ans.push_back(lol);
            }
            //smap[s[i-psize]]--;
            if(!--smap[s[i-psize]])smap.erase(s[i-psize]);
            smap[s[i]]++;
            lol++;
        }
        if(smap==pmap)ans.push_back(lol);
        return ans;
    }
};
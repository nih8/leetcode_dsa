#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        if(t.size()==0)return "";
        if(t==s)return s;
        unordered_map<char,int>tmap;
        int tcount=0;
        for(char c :t){
            tmap[c]++;
            tcount++;
        }
        int ttemp = tcount;
        int l =0;
        int ansl=0;
        int ansr=INT_MAX;
        unordered_map<char,int>window;
        for(int i=0;i<s.size();i++){
            if(tmap.find(s[i])!=tmap.end()){
                if(window[s[i]]<tmap[s[i]]){
                    window[s[i]]++;
                    ttemp--;
                }
                else{
                    window[s[i]]++;
                }
            }
            if(ttemp==0){
                //cout<<"ttemp is zero";
                while(true){
                    if(tmap.find(s[l])==tmap.end()) l++;
                    else if(window[s[l]]>tmap[s[l]]){
                        window[s[l]]--;
                        l++;
                    }
                    else break;
                }
                if(ansr-ansl>i-l){
                    ansr = i;
                    ansl = l;
                }
                ttemp+=1;
                window[s[l]]--;
                l++;
                
            }
        }
        if(ansr==INT_MAX)return "";
        else return s.substr(ansl,ansr-ansl+1);


        
    }
};
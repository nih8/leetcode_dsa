#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool banana(vector<int>& piles, int h,int rate){
        int curr=0;
        for(int num:piles){
            curr += (num + rate-1)/rate;
            if(curr>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int maxx=0;
        for(int num:piles){
            maxx = max(maxx,num);
        }
        int r = maxx;
        while(l<r){
            int m = (l+r)/2;
            if(banana(piles,h,m)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
};
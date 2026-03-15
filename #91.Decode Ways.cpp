#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i==0 || (s[i-1]!='1' && s[i-1]!='2')){
                    return 0;
                }
                else{
                    dp[i+1] = dp[i-1];  //the part where i was wrong
                    //here it should be dp[i-1] because the digit before 0 has to be pared with 0, it has no other choice, hence we take the dp of the prev number, because in simple words, the number exactly before zero has no choice of pairing with the number before it :)
                }
            }
            else{
                int curr = s[i]-'0';
                if(i==0){
                    dp[i+1]=dp[i];
                    continue;
                }
                int curr_1= s[i-1] -'0';
                if(curr_1==1 || (curr_1==2 && curr<=6) ){
                    dp[i+1] = dp[i]+dp[i-1];
                }
                else{
                    dp[i+1] = dp[i];
                }
            }
            //cout<<dp[i+1]<<endl;
        }
        return dp[n];
    }
};
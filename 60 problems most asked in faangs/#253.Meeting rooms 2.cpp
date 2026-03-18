#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;int j=0;
        int room=0;
        int maxrooms=0;
        int n = start.size();
        while(i<n){
            if(start[i]<end[j]){
                i++;
                room++;
            }
            else{
                room--;
                j++;
            }
            maxrooms = max(maxrooms,room);
        }
        return maxrooms;
    }
};

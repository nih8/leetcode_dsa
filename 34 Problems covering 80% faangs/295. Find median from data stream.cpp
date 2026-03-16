#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>minn;
    priority_queue<int,vector<int>,greater<int>>maxx;
    
    void addNum(int num) {
        if(maxx.empty()){
            maxx.push(num);
        }
        else{
            if(num>maxx.top()){
                maxx.push(num);
            }
            else{
                minn.push(num);
            }
        }
        if(minn.size()-maxx.size()==2){
            int lol = minn.top();
            minn.pop();
            maxx.push(lol);
        }
        if(minn.size()-maxx.size()==-2){
            int lol = maxx.top();
            maxx.pop();
            minn.push(lol);
        }
    }
    
    double findMedian() {
        if(maxx.size()!=minn.size()){
            double ans = maxx.size()>minn.size()? maxx.top()*1.0 : minn.top()*1.0;
            return ans;
        }
        else{
            double ans = (maxx.top() + minn.top())/2.0;
            return ans;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
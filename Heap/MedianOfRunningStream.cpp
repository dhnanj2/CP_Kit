#include<bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> q1;   //max heap
    priority_queue<int,vector<int>,greater<int>> q2;   //min heap
    
     MedianFinder() {}
    
    void addNum(int num) {
        if(q1.size()==q2.size()) {
            if(q1.empty()||num<q1.top())q1.push(num);
            else q2.push(num);
        }
        else if(q1.size()>q2.size()) {
            if(num>=q1.top()) q2.push(num);
            else {
                int t=q1.top();
                q1.pop();
                q2.push(t);
                q1.push(num);
            }
        }else {
            if(num<=q2.top()) q1.push(num);
            else {
                int t=q2.top();
                q2.pop();
                q1.push(t);
                q2.push(num);
            }
        }
    }
    
    double findMedian() {
        int n=q1.size()+q2.size();
        
        if(n%2) return q1.size()>q2.size()?q1.top():q2.top();
        
        return ((double)q1.top()+q2.top())/2;
    }
    
};

int main()
{

    return 0;
}
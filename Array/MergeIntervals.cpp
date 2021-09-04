#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    auto cmp = [](vector<int> l, vector<int> r){return l[0]<r[0];} ;
    sort(intervals.begin(),intervals.end(),cmp);
    vector<vector<int>> ans;
    for(auto i=0;i<intervals.size();) {
        int lo=intervals[i][0] , hi = intervals[i][1];
        int j=i+1;
        while(j<intervals.size() && intervals[j][0] <= hi) {
            hi = max(intervals[j++][1],hi);
        }
        vector<int> newInterval{lo,hi};
        ans.push_back(newInterval);
        i=j;
    }
    return ans;
}

int main()
{

return 0;
}
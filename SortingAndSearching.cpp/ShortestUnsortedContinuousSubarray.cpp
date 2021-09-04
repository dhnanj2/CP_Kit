#include<bits/stdc++.h>

using namespace std;

// Time : O(nlogn+n) , space:O(n)
int findUnsortedSubarray(vector<int>& nums) {
    auto s = nums;
    sort(s.begin(),s.end());
    int beg=INT_MAX , end=0;
    for(auto i=0;i<s.size();) {
        int j=i;
        while(j<s.size() && s[j]!=nums[j]) j++;
        if(j!=i) 
        {
            beg = i<beg? i:beg;
            end=j;
        }             
        i=j+1;
    }
    return beg==INT_MAX? 0:end-beg;
}

int main()
{

    return 0;
}
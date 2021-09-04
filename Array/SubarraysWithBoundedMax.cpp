#include<bits/stdc++.h>

using namespace std;

// Let count(bound) is the number of subarrays which have all elements less than or equal to bound.
// Finally, count(right) - count(left-1) is our result.

class Solution {
public:
    vector<int> a;

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        a=nums;
        return count(right)-count(left-1);
    }
    
    int count(int x) {
        int c=0,ans=0;
        for(auto i:a) {
            c = i<=x ? c+1:0;
            ans += c;
        }
        return ans;
    }
};

int main()
{

return 0;
}
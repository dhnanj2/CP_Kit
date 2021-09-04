/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

//Solution:  dp[i] stores the maximum length of increasing subsequence starting with arr[i]
#include<bits/stdc++.h>

using namespace std;

// https://www.youtube.com/watch?v=TocJOW6vx_I 
// O(NLogN) 
int longestSubsequence(int n, int a[])
{
    int ans=0;
    set<int> s;   //stores the LIS
    for(int i=0;i<n;i++) {
        auto it=s.lower_bound(a[i]);
        if(it!=s.end()) s.erase(it);
        s.insert(a[i]);
    }
    return s.size();
}

// O(N^2)
int lengthOfLIS(vector<int>& a) {
    int ans=1;
    vector<int> dp(a.size(),1);
    for(int i=a.size()-1;i>=0;i--) {
        int len=1;
        for(int j=i+1;j<a.size();j++) {
            if(a[j]>a[i]) {
                len=max(dp[j]+1,len);
            }
        }
        dp[i]=len;
        ans=max(ans,len);
    }
    return ans;
}

int main()
{

    return 0;
}

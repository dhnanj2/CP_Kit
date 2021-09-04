/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.
An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104

   Hide Hint #1  
The main point here is for the subarray to contain unique elements for each index. Only the first subarrays starting from that index have unique elements.
   Hide Hint #2  
This can be solved using the two pointers technique
*/
#include<bits/stdc++.h>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    vector<int> pre(nums.size(),0);
    pre[0]=nums[0];
    for(int i=1;i<nums.size();i++) {
        pre[i]=pre[i-1]+nums[i];
    }
    vector<int> m(1e4+1,-1);
    int ans=0,l=-1;
    for(int i=0;i<nums.size();i++) {
        if(m[nums[i]]>l) {
            l=m[nums[i]];                            
        }
        m[nums[i]] = i;
        ans=max(ans,pre[i]-(l>=0?pre[l]:0));
    }
    return ans;
}

int main()
{
    return 0;
}
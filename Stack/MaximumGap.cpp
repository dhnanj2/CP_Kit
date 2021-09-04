/*
Maximum Gap
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 
Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 109
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(N), space:O(N)
vector<int> NGR(vector<int> a, int n){
    vector<int> ans(1,-1);
    stack<int>  stk;
    stk.push(a[n-1]);
    for(int i=n-2;i>=0;i--)  {
        while(!stk.empty() && stk.top()<=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// time : O(N), space:O(N)
vector<int> NGL(vector<int> a, int n){              // next greater element to left
    vector<int> ans(1,-1);
    stack<int>  stk;
    stk.push(a[0]);
    for(int i=1;i<n;i++)  {
        while(!stk.empty() && stk.top()<=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    return ans;
}

// time : O(N), space:O(N)
vector<int> NSL(vector<int> a, int n){              // next smaller element to left
    vector<int> ans(1,-1);
    stack<int>  stk;
    stk.push(a[0]);
    for(int i=1;i<n;i++)  {
        while(!stk.empty() && stk.top()>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    return ans;
}

// time : O(N), space:O(N)
vector<int> NSR(vector<int> a, int n){              // next smaller element to right
    vector<int> ans(1,n);
    stack<int>  stk;
    stk.push(a[n-1]);
    for(int i=n-2;i>=0;i--)  {
        while(!stk.empty() && stk.top()>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(n);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;   
}

int maximumGap(vector<int>& nums) {
    auto ngr=NGR(nums,nums.size());
    // auto nsr=NSR(nums,nums.size());
    auto ngl=NGL(nums,nums.size());
    // auto nsl=NSL(nums,nums.size());
    int ans=0;
    for(auto i=0;i<nums.size();i++) {
        int diff=max(ngr[i]-nums[i],ngl[i]-nums[i]);
        ans=max(diff,ans);
    } 
    return ans;
}

int main()
{

    return 0;
}
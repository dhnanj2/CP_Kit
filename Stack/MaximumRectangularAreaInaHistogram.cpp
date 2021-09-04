/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
*/
/*
ALGORITHM: 
    1. build NSR and NSL of the given array using stack approach.
    2. traverse the array and for each iteration determine the corresponding area as (nsr[i]-nsl[i]-1) 
    3. return max area
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(N), space:O(N)
vector<long long> NSL(vector<long long> a, int n){              // next smaller element to left
    vector<long long> ans(1,-1);
    stack<long long>  stk;
    stk.push(0);
    for(int i=1;i<n;i++)  {
        while(!stk.empty() && a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(i);
    }
    return ans;
}

// time : O(N), space:O(N)
vector<long long> NSR(vector<long long> a, int n){              // next smaller element to right
    vector<long long> ans(1,n);
    stack<long long>  stk;
    stk.push(n-1);
    for(int i=n-2;i>=0;i--)  {
        while(!stk.empty() && a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(n);
        else ans.push_back(stk.top());
        stk.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;   
}

// time : O(N), space:O(N)
long long getMaxArea(long long arr[], int n) {
    vector<long long> a(arr,arr+n);
    auto nsr = NSR(a,n);    
    auto nsl = NSL(a,n);
    long long ans=1;
    for(int i=0;i<n;i++) {
        auto area = (nsr[i]-nsl[i]-1)*a[i];
        ans = max(ans,area);
    }
    return ans;
}

int main()
{
    
    return 0;
}
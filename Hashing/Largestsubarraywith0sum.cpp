/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(N) , space: O(N)
int maxLen(int A[], int n)
{
    unordered_map<int,int> rmi;         // rightmost occurance(index) of 'sum' in prefix sum array
    unordered_map<int,int> lmi;         // leftmost occurance(index) of 'sum' in prefix sum array
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=A[i];
        if(rmi[sum]<=i) rmi[sum]=i;
        if(lmi.find(sum)==lmi.end())  lmi[sum]=i;
    }
    int ans=0;
    for(auto i:rmi) {
        if(i.first==0) ans=max(ans,i.second+1);
        else {
            ans = max(ans,i.second-lmi[i.first]);
        }
    }
    return ans;
}

int main()
{
    int a[]={15,-2 ,2 ,-8 ,1 ,7 ,10,23};
    cout<<maxLen(a,8);
    return 0;
}
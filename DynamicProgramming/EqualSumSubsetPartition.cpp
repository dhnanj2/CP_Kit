/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Example 1:
Input:
N = 4
arr[] = {1,5,11,5}
Output: YES
Explanation: There exists two subsets
such that {1, 5, 5} and {11}.

Example 2:
Input:
N = 3
arr[] = {1,3,5}
Output: NO
Your Task:
Your task is to complete the findPartition() function which takes an array a[] and N as input parameter and return true if the given set can be partitioned into two subsets such that the sum of elements in both subsets is equal, else return false.
Note: The output will be YES or NO depending upon the value returned by your code. The printing is done by the driver's code.

Expected Time Complexity: O(N*S).
Expected Auxiliary Space: O(S) where S is the sum of the given Array.

Constraints:
1 <= N <= 100
0 <= arr[i] <= 1000
*/
#include<bits/stdc++.h>

using namespace std;

    bool subsetSumK(int a[],int n, int k)
    {
        bool dp[n+1][k+1]={0};
        for(int i=0;i<=n;i++) {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++) {
            // cout<<a[i-1]<<" ";
            for(int j=1;j<=k;j++) {
                if(a[i-1]>j) dp[i][j]=dp[i-1][j];
                else if(dp[i-1][j] || dp[i-1][j-a[i-1]]) dp[i][j]=1;
            }
        }
        return dp[n][k];
    }

    bool findPartition(int a[], int n)
    {
        int sum=accumulate(a,a+n,0);   
        if(sum%2) return false; //if array sum is odd then no partition possible
        return subsetSumK(a,n,sum/2); //if array sum is even then partition is possible only if there exist a subset with sum=arraySum/2;
    }


int main()
{

    return 0;
}
/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.
There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.

Example 2:
Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200
*/
#include<bits/stdc++.h>

using namespace std;

// optimise the worst case(min of the max attempts at every floor)
// O(N*K*K)
int eggDrop(int n, int k) 
{
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for(int e=1;e<=n;e++) {
        for(int f=1;f<=k;f++) {
            if(e==1) dp[e][f]=f;        
            else if(f==1) dp[e][f]=1;        
            else {
                int mn=200;
                for(int i=0,j=f-1;j>=0 && i<f;j--,i++) {
                    mn=min(mn,max(dp[e][j],dp[e-1][i]));
                }
                dp[e][f]=mn+1;
            }
        }
    }
    return dp[n][k];
}

int main()
{
    return 0;
}
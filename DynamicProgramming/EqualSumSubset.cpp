#include<bits/stdc++.h>

using namespace std;

// returns true if there's a possible subset of 'a' with sum 'k'
// time : O(N*K) , space : O(N*K)
bool subsetSumK(vector<int> &a, int k)
{
    vector<vector<bool>> dp(a.size()+1,vector<bool> (k+1,0));
    for(int i=0;i<=a.size();i++) {
        dp[i][0]=1;
    }
    for(int i=1;i<=a.size();i++) {
        for(int j=1;j<=k;j++) {
            if(a[i-1]>j) dp[i][j]=dp[i-1][j];
            else if(dp[i-1][j] || dp[i-1][j-a[i-1]]) dp[i][j]=1;
        }
    }
    return dp[a.size()][k];
}

// returns true if array can be partitioned into two subset with equal sums;
bool canPartition(vector<int>& nums) {
    long long sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2!=0) return 0;
    return  subsetSumK(nums,sum/2);
}

int main()
{
    return 0;
}
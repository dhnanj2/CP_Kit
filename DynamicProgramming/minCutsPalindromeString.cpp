/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1

Constraints:
1 <= s.length <= 2000
s consists of lower-case English letters only.
*/
#include<bits/stdc++.h>

using namespace std;

int minCut(string s) {
    int n=s.size();
    vector<vector<int>> check(n,vector<int>(n,0)); // check[i][j]=true if s[i..j] is palindrome, else its false
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>=i;j--) {
            if(i==j) check[i][j]=1;
            else if(i+1==j) check[i][j]=(s[i]==s[j]);
            else if(check[i+1][j-1] && s[i]==s[j]) check[i][j]=1;
        }
    }
    vector<int> dp(n,0); // dp[i] stores the min cuts for s[0..i]
    for(int i=1;i<n;i++) {
        // get the longest palindromic suffix of the string s[0..j]
        if(check[0][i]) {
            dp[i]=0;
            continue;
        }
        int j=i;
        dp[i]=i;
        while(j>=1) {
            if(check[j][i]) dp[i]=min(dp[j-1]+1,dp[i]);
            j--;
        }
    }
    // for(auto i:dp)  cout<<i<<" ";
    return dp[n-1];
}
int main()
{
    cout<<minCut("aabaa");
    return 0;
}

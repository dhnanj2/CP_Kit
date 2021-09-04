/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:
Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

Example 2:
Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/
#include<bits/stdc++.h>

using namespace std;

// time = space = O(x*y)
int lcs(int x, int y, string s1, string s2)
{
    //dp[i][j]=lcs(s1[x,x-1,...i],s2[y,y-1,...j])
    vector<vector<int>> dp(x+1,vector<int>(y+1,0)); 
    for(int i=x-1;i>=0;i--) {
        for(int j=y-1;j>=0;j--) {
            // let lcs(s1,s2) = lcs(c1+r1,c2+r2)
            // if c1==c2
            if(s1[i]==s2[j]) {
                // 1+lcs(r1,r2)
                dp[i][j]=1+dp[i+1][j+1];
            }else {
                // max(lcs(r1,s2),lcs(s1,r2))
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main()
{

    return 0;
}
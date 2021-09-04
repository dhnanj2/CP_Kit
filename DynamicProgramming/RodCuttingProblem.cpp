/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

*/
#include<bits/stdc++.h>

using namespace std;

int maxCost(int a[],int n) {
    vector<int> dp(n+1,0);  //dp[i]=max. profit earned using rod of length i
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            dp[i+1]=max(dp[i+1],dp[i-j]+a[j]);    
        }
    }
    return dp[n];
}

int main()
{
    int a[]={1,5,8,9,10,17,17,20};
    cout<<maxCost(a,8);
    return 0;
}
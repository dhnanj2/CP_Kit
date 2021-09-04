/*
You are given an amount denoted by value. You are also given an array of coins. The array contains the
denominations of the give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.

Example 1:
Input:
value = 5
numberOfCoins = 3
coins[] = {3,6,3}
Output: Not Possible
Explanation:We need to make the change for
value = 5 The denominations are {3,6,3}
It is certain that we cannot make 5 using
any of these coins.

Example 2:
Input:
value = 10
numberOfCoins = 4
coins[] = {2 5 3 6}
Output: 2
Explanation:We need to make the change for
value = 10 The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So
minimum coins are 2.
Your Task:
You only need to complete the function minimumNumberOfCoins() that take array of coins, size of array, and value as parameters. You need to return the minimum number of coins required. If it is not possible to make the exact value out of the given coin denominations, return -1 ("Not Possible" will be printed by the driver's code in this case).

Expected Time Complexity: O(number of coins * value).
Expected Auxiliary Space: O(value)

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
*/

#include<bits/stdc++.h>

using namespace std;

long long minimumNumberOfCoins(int coins[],int n,int value)
{
    vector<long long> dp(value+1,1e5);
    dp[0]=0ll;
    for(int i=0;i<n;i++) {
        int c=coins[i];
        for(int v=c;v<=value;v++) {
            dp[v]=min(dp[v-c]+1,dp[v]);
        }
    }
    return dp[value]<1e5?dp[value]:-1;
}

int main()
{

return 0;
}
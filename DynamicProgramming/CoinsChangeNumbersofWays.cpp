#include<bits/stdc++.h>

using namespace std;

long long numberOfWays(int coins[],int n,int value)
{
    vector<long long> dp(value+1,0);
    dp[0]=1;
    for(int j=0;j<n;j++) {
        int c=coins[j];
        for(int i=c;i<=value;i++) {
            dp[i]+=dp[i-c];
        }
    }
    return dp[value];
}

int main()
{

return 0;
}
/*
Given a matrix of size M x N, there are large number of queries to find submatrix sums. 
Inputs to queries are left top and right bottom indexes of submatrix whose sum is to find out.

How to preprocess the matrix so that submatrix sum queries can be performed in O(1) time.

Example :
tli :  Row number of top left of query submatrix
tlj :  Column number of top left of query submatrix
rbi :  Row number of bottom right of query submatrix
rbj :  Column number of bottom right of query submatrix

Input: mat[M][N] = {{1, 2, 3, 4, 6},
                    {5, 3, 8, 1, 2},
                    {4, 6, 7, 5, 5},
                    {2, 4, 8, 9, 4} };
Query1: tli = 0, tlj = 0, rbi = 1, rbj = 1
Query2: tli = 2, tlj = 2, rbi = 3, rbj = 4
Query3: tli = 1, tlj = 2, rbi = 3, rbj = 3;

Output:
Query1: 11  // Sum between (0, 0) and (1, 1)
Query2: 38  // Sum between (2, 2) and (3, 4)
Query3: 38  // Sum between (1, 2) and (3, 3)
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define print(v)    for(auto i:v) cout<<i<<" ";

#define pii pair<int,int>

#define ll long long 

#define pb push_back

#define S second

#define F first

const int MOD = 1e9+7;

static const auto __optimize__ = []() {

std::ios::sync_with_stdio(false);

std::cin.tie(nullptr);

std::cout.tie(nullptr);

return 0;

}();


// Time:O(NxM) , space:O(NxM)
void buildDP(vector<vector<int>> &mat, vector<vector<ll>> &dp) {
    int n=mat.size();
    int m=mat[0].size();
    dp.resize(n,vector<ll> (m,0));
    dp[0][0]=mat[0][0];
    FOR(i,1,m,1)  {
        dp[0][i] = dp[0][i-1] + mat[0][i];
    }
    FOR(i,1,n,1)  {
        dp[i][0] = dp[i-1][0] + mat[i][0];
    }
    FOR(i,1,n,1) {
        FOR(j,1,m,1) {
            dp[i][j]=mat[i][j]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
        }
    }
}

// Time:O(1) , space:O(NxM)
ll submatrixSum(int r1,int c1,int r2,int c2,vector<vector<ll>> &dp) {
    ll res = dp[r2][c2];
    if(r1-1>=0)  res -= dp[r1-1][c2];
    if(c1-1>=0)  res -= dp[r2][c1-1];
    if(r1-1>=0 && c1-1>=0) res += dp[r1-1][c1-1];
    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {2,2,3},
        {3,4,5},
        {4,5,5}
    };   
    vector<vector<ll>> dp;
    buildDP(mat,dp);
    cout<<submatrixSum(1,0,2,1,dp);
    return 0;
}
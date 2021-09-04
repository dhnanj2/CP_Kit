/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][j]==0) {
                    q.emplace(i,j);
                }                
            }
        }
        q.emplace(-1,-1);
        int lvl=0;
        while(!q.empty()) {
            auto p=q.front();
            int i=p.first,j=p.second;
            q.pop();
            if(i<0) {
                if(q.empty())break;
                q.emplace(-1,-1);
                lvl++;
                continue;
            }
            dp[i][j]=lvl;
            if(i+1<m && a[i+1][j]==1) {
                a[i+1][j]=0;
                q.emplace(i+1,j);
            }if(i-1>=0 && a[i-1][j]==1) {
                a[i-1][j]=0;
                q.emplace(i-1,j);
            }if(j+1<n && a[i][j+1]==1) {
                a[i][j+1]=0;
                q.emplace(i,j+1);
            }if(j-1>=0 && a[i][j-1]==1) {
                a[i][j-1]=0;
                q.emplace(i,j-1);
            }
        }
        return dp;
    }
};

int main()
{

    return 0;
}
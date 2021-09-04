/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges
We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

Example 1:
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.

Example 2:
Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)
*/
#include<bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& g) {
        int ans=0,n=g.size(),m=g[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<g.size();i++) {
            for(int j=0;j<g[i].size();j++) {
                if(g[i][j]==2)q.emplace(i,j);           
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
                ans=max(ans,++lvl);
                continue;
            }
            if(i+1<n && g[i+1][j]==1) {
                g[i+1][j]=0;
                q.emplace(i+1,j);
            }if(i-1>=0 && g[i-1][j]==1) {
                g[i-1][j]=0;
                q.emplace(i-1,j);
            }if(j+1<m && g[i][j+1]==1) {
                g[i][j+1]=0;
                q.emplace(i,j+1);
            }if(j-1>=0 && g[i][j-1]==1) {
                g[i][j-1]=0;
                q.emplace(i,j-1);
            }
        }
        for(int i=0;i<g.size();i++) {
            for(int j=0;j<g[i].size();j++) {
                if(g[i][j]==1)return -1;           
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
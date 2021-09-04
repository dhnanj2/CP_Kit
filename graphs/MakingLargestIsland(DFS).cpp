/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    //we use the concept of leetcode 695- maximum area of island
    //we assign all connected islands with different id's 
    //we do it inplace
    //we then store the area of the island id in a hashmap
    
    //we again iterate through the isalnd and when we have zero
    //we push all the 4 adjacent cell's island id to hashset to get the unique id's
    //the we calculate the sum of the area of each id in hashset and update the result
    vector<int> offsets={0,1,0,-1,0};
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        unordered_map<int,int> area;
        
        int maxArea=0;
        int currArea=0;
        int island_id=2;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    calc(grid,i,j,currArea,n,island_id);
                    maxArea=max(maxArea,currArea);
                    //store the area of the island using its id
                    area[island_id]=currArea;
                    currArea=0;
                    island_id++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> st;
                    for(int k=0;k<4;k++)
                    {
                        int x=i+offsets[k];
                        int y=j+offsets[k+1];
                        if(x<0 || y<0 || x>=n || y>=n || grid[x][y]==0)
                            continue;
                        st.insert({grid[x][y]});
                    }
                    
                    int total=1;
                    for(auto i:st){
                        total+=area[i];
                    
                    }
                    maxArea=max(maxArea,total);
                }
            }
        }
        
        return maxArea;
        
        
        
    }
	
	//calculates the area of island
    void calc(vector<vector<int>>& grid,int i,int j,int& currArea,int& n,int& island_id)
    {
        currArea++;
        //store the island id to which the current cell belongs to
        grid[i][j]=island_id;
        for(int k=0;k<4;k++)
        {
            int x=i+offsets[k];
            int y=j+offsets[k+1];
            if(x<0 || y<0 || x>=n || y>=n || grid[x][y]!=1)
                continue;
            calc(grid,x,y,currArea,n,island_id);
        }
        
        
    }
};

int main()
{

    return 0;
}
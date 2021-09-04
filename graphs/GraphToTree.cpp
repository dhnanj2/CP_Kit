/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example 1:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,bool> vis;
    unordered_map<int,vector<int>> adj;
    
    void helper(int cur, int prev=-1) {
        if(cur>adj.size()) return;
        if(vis[cur]) {
            ans.push_back(vector<int> {cur,prev});
            return;
        }
        vis[cur]=true;
        for(auto i:adj[cur]) {
            if(prev!=i) helper(i,cur);
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=edges.size();i++) {
            vis.clear();
            helper(i);
        }
        for(int i=edges.size()-1;i>=0;i--) {
            for(auto j:ans) {
                if(j==edges[i]) return j;
                else if(j[1]==edges[i][0] && j[0]==edges[i][1]) return edges[i];
            }
        }
        return ans[0];
    }
};

int main()
{

    return 0;
}
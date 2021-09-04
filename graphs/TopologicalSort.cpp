#include<bits/stdc++.h>

using namespace std;

// Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<bool> vis;
	
	void visit(int u,vector<int> adj[],int V,vector<int> &ans,int prev=-1) {
	    vis[u]=1;
	    for(auto v:adj[u]) {
	        if(v==prev) continue;
	        if(!vis[v]) {
	            visit(v,adj,V,ans,u);
	        }
	    }
	    ans.push_back(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vis.resize(V,0);
	    vector<int> ans;
	    vector<int> t;
	    for(int i=0;i<V;i++) {
	        t.push_back(i);
	    }
	    auto cmp=[=](int l,int r) {
	        return adj[l].size()>adj[r].size();
	    };
	    sort(t.begin(),t.end(),cmp);
	    for(auto i:t) {
	       // cout<<i<<" ";
	        if(!vis[i]) {
	            visit(i,adj,V,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	   // for(auto i:ans) cout<<i<<" ";
	    return ans;
	}
};

int main()
{

    return 0;
}
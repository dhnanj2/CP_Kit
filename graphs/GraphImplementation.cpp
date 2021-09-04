#include<bits/stdc++.h>

using namespace std;

template<typename T> 
class graph {

        unordered_map<T,list<pair<int,T>>> adj; 
        
        bool isCyclicUtil(T v, unordered_map<T,bool> &visited,unordered_map<T,bool> &recStack)
        {
            if(visited[v] == false)
            {
                // Mark the current node as visited and part of recursion stack
                visited[v] = true;
                recStack[v] = true;
        
                // Recur for all the vertices adjacent to this vertex
                for(auto i:adj[v])
                {
                    if ( !visited[i.second] && isCyclicUtil(i.second, visited, recStack) )
                        return true;
                    else if (recStack[i.second])
                        return true;
                }
        
            }
            recStack[v] = false;  // remove the vertex from recursion stack
            return false;
        }

    public:

        graph() {}

        void addEdge(T sourceNode,T DestinationNode,int weight=1,bool directed=false ) {
            adj[sourceNode].emplace_back(weight,DestinationNode);
            if(!directed && sourceNode!=DestinationNode) adj[DestinationNode].emplace_back(weight,sourceNode);
        }

        bool isConnected(T u,T v) {
            for(auto i:adj[u]) {
                if(i.second==v) return true;
            }
            return false;
        }

        int cntNodes() {
            return adj.size();
        }
        
        //time : O(ElogV)
        //returns dist of all nodes from 'src' node 
        unordered_map<T,int> Dijkstra(T src) {
            unordered_map<T,int> dist;
            for(auto i:adj) {
                dist[i.first]=INT_MAX;
            }
            dist[src]=0;
            set<pair<int,T>> s;
            s.emplace(0,src);
            while(!s.empty()) {
                T u=s.begin()->second;
                s.erase(s.begin());
                for(auto i:adj[u]) {
                    T v=i.second;
                    int w=i.first;
                    // relaxation
                    if(dist[v]>dist[u]+w) {
                        dist[v]=dist[u]+w;
                        s.emplace(dist[v],v);
                    }        
                }
            }
            return dist;
        }

        /*
        As a matter of fact any undirected graph is also a directed graph.
        You just have to specify any edges {u, v} twice (u, v) and (v, u).
        But don't forget, that this also means any edge with a negative weight will count as a loop. 
        As the Bellman-Ford algorithm ONLY works on graphs that don't contain any cycles with negative weights this actually means your un-directed graph mustn't contain any edges with negative weight.
        If it doesn't its pretty fine to use Bellmann-Ford.
        */
        //time : O(VE) 
        //returns dist of all nodes form 'src' node(works for -ve wighted graphs too, but fails at -ve cycles)
        unordered_map<T,int> bellmanFord(T src) {
            unordered_map<T,int> dist;
            for(auto i:adj) {
                dist[i.first]=1e9;
            }
            dist[src]=0;
            int n=adj.size();
            for(int i=1;i<n;i++) {
                for(auto j:adj) {
                    int u=j.first;
                    for(auto x:j.second) {
                        int v=x.second;
                        int w=x.first;
                        // relaxation
                        if(dist[v]>dist[u]+w) {
                            dist[v]=dist[u]+w;
                        }
                    }
                }
            }
            return dist;
        }

    // O(V+E)
    // Returns true if the graph contains a cycle, else false.
    bool isCyclic()
    {
        // Mark all the vertices as not visited and not part of recursion
        // stack
        unordered_map<T,bool> visited;
        unordered_map<T,bool> recStack;
        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for(auto i:adj)
            if (isCyclicUtil(i.first, visited, recStack))
                return true;

        return false;
    }
};

int main()
{
    graph<int> g;
    g.addEdge(1,2,2,true);
    g.addEdge(3,2,2,true);
    g.addEdge(3,1,-2,true);
    g.addEdge(1,4,2,true);
    g.addEdge(4,3,1,true);
    // auto shortestDist=g.bellmanFord(1);
    // for(auto i:shortestDist) {
    //     cout<<"from "<<1<<" to "<<i.first<<" = "<<i.second<<"\n";
    // }
    // cout<<g.isCyclic();
    int a[2] = {-1};
    for(auto i:a)cout<<i<<" ";
    return 0;
}


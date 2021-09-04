#include<bits/stdc++.h>

using namespace std;

class DisjointSet { //to represent disjoint set
   unordered_map<int, int> parent;
   
   public:

   void makeSet(vector<int> const &wholeset){
      //perform makeset operation
      for (int i : wholeset) // create n disjoint sets
        parent[i] = i;
   }

   int Find(int l) {       // Find the root of the set in which element l is present
      if (parent[l] == l) // if l is root
         return l;
      return parent[l] = Find(parent[l]); // recurs for parent till we find root
   }

   void Union(int m, int n) { // perform Union of two subsets m and n  
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }
};

int main()
{
    
    return 0;
}
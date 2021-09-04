
#include<bits/stdc++.h>

using namespace std;

// Time:O(N), space:O(N)
int firstRepeated(int arr[], int n) {
    unordered_map<int,int> vis;
    int ans=INT_MAX;
    for(int i=0;i<n;i++) {
        if(vis[arr[i]]>0) ans=min(ans,vis[arr[i]]);
        else vis[arr[i]]=i+1;
    }
    return ans==INT_MAX?-1:ans;
}

int main()
{

return 0;
}
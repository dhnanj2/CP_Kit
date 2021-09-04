#include<bits/stdc++.h>

using namespace std;

// time:O((N/K)*K)=O(N) , space:O(1)
void reverseInGroups(vector<long long>& arr, int n, int k){
    int l=0, r=k;
    while(r<n) {
        // cout<<l<<" "<<r<<" ";
        reverse(arr.begin()+l,arr.begin()+r);
        l=r;
        r=min(l+k,n);
    }
    reverse(arr.begin()+l,arr.end());
    // cout<<endl;
}

int main()
{

return 0;
}
#include<bits/stdc++.h>

using namespace std;

int sb(int arr[], int n, int x)
{
    // generate orefix suma array 
    int pref[n+1] = { };
    pref[0]=0;
    for(int i=1;i<=n;i++) {
        pref[i]=pref[i-1]+arr[i-1];
    }
    // search for the pair of indices(first and last) of the required subarray using 2 pointers
    int i=0, j=1, ans=INT_MAX;
    while(j<=n) {
        if(pref[j]-pref[i]>x) {
            ans=min(ans,(j-i));
            i++;
            if(i>j) j++;
        }
        else j++;
    }
    // cout<<j<<" "<<i<<" ";
    return ans;   
}

int main()
{
    
    return 0;
}
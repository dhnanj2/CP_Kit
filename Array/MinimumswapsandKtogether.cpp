/*
A simple approach is to use two pointer technique and sliding window.

Find count of all elements which are less than or equals to ‘k’. Let’s say the count is ‘cnt’
Using two pointer technique for window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
Repeat step 2, for every window of length ‘cnt’ and take minimum of count ‘bad’ among them. This will be the final answer.
*/
#include<bits/stdc++.h>

using namespace std;

// time:O(N), space:O(1)
int minSwap(int *arr, int n, int k) {
    // Complet the function
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(arr[i]<=k) cnt++;
    }
    int l=0,r=cnt-1,grt_than_k=0;
    for(int i=0;i<=r;i++) {
        if(arr[i]>k) grt_than_k++;
    }
    int ans=grt_than_k;
    for(int i=cnt;i<n;i++) {
        if(arr[i]>k) grt_than_k++;
        if(arr[l++]>k) grt_than_k--;
        grt_than_k=min(ans,grt_than_k);
    }    
    return ans;
}

int main()
{

    return 0;
}
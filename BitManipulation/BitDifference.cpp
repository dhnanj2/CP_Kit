#include<bits/stdc++.h>

using namespace std;

long long sumBitDiff(int arr[], int n) 
{ 
    int set[32]={ };
    for(int b=0;b<32;b++) {
        for(int i=0;i<n;i++) {
            if((arr[i]&(1<<b))!=0) set[b]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int b=0;b<32;b++) {
            if((arr[i]&(1<<b))!=0) ans+=(n-set[b]);
            else ans+=set[b];
        }
    }
    return ans;
}

int main()
{

    return 0;
}
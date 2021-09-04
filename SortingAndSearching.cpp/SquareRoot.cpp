// Problem : https://practice.geeksforgeeks.org/problems/square-root/1/?track=dsa-workshop-1-search-sort&batchId=308
#include<bits/stdc++.h>

using namespace std;

long long int floorSqrt(long long int x) 
{
    long long r=x,l=1;
    long long ans=1;
    while(l<=r) {
        auto mid = l+(r-l)/2;
        if(mid*mid==x) return mid;
        else if(mid*mid<x) {
            ans=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return ans;
}

int main()
{

return 0;
}
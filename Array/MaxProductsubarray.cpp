/*
At each i we'll have 3 choice :-
    1. to only take ith element
    2. to take maxProd till i multiplied by ith element
    3. to take minProd till i multiplied by ith element
ans will be max({c1,c2,,c3})    
*/
#include<bits/stdc++.h>

using namespace std;

long long maxProduct(int *a, int n) {
    long long maxP=a[0];
    long long minP=a[0];
    long long ans=a[0];    
    for(int i=1;i<n;i++) {
        auto c1 = maxP*a[i];
        auto c2 = minP*a[i];
        maxP = max({c1,c2,(long long)a[i]});
        minP = min(c2,minP);
        ans = max(ans,maxP);
    }
    return ans;
}
int main()
{

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// raises a to power b(a +ve no.) in O(logb) time
ll powatob(ll a, ll b) {
    int mod=1e9+7;
    if(!b || a==1) return 1;
    ll res=1;
    if(b&1) res = (a%mod*powatob(a,b-1)%mod)%mod;
    else {
        res = powatob(a,b>>1)%mod;
        res = (res*res)%mod;
    }
    return res;
}

int main()
{
    cout<<powatob(2,10000000000);
    return 0;
}
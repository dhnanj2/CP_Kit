#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define print(v)    for(auto i:v) cout<<i<<" ";

#define pii pair<int,int>

#define ll long long 

#define pb push_back

#define S second

#define F first

const int MOD = 1e9+7;

static const auto __optimize__ = []() {

std::ios::sync_with_stdio(false);

std::cin.tie(nullptr);

std::cout.tie(nullptr);

return 0;

}();

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> a(n,0);
        for(auto &i:a) cin>>i;
        ll sum=0;
        FOR(i,n-1,-1,-1) {
            if(a[i]>0) {
                ll x=a[i];
                a[i] = max(a[i]+sum,0ll);
                sum = min(x+sum,0ll);
            }
            else sum+=a[i];
        }
        ll ans=0;
        for(auto i:a) {
            if(i>0) ans+=i;
        }
        // print(a);
        cout<<ans<<"\n";
    }
    return 0;
}
// problem : https://www.codechef.com/OCT18A/problems/HMAPPY
/*
    solution :https://discuss.codechef.com/t/hmappy-editorial/20574    
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

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
    ll n=0;
    ll m=0;
    cin>>n>>m;
    vector<ll> a(n,0);
    vector<ll> b(n,0);
    ll sum=0;
    for(auto &i:a) {
        cin>>i;
        sum+=i;       
    }
    ll low=0 , high=0;
    FOR(i,0,n,1) {
        cin>>b[i];
        high = max(high,(ll)(a[i]*b[i]));
    }
    if(m>=sum) {
        cout<<0<<'\n';
        return 0;
    }
    ll ans=(low+high)/2;
    while(low<=high){
        auto mid= (low+high)/2;
        ll min_total_ballons = 0;
        FOR(i,0,n,1) {
            min_total_ballons += max(0ll,(a[i]-mid/b[i]));
        }
        if(min_total_ballons<=m) {
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
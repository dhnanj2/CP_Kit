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
        double n,k;
        cin>>n>>k;
        int mul=ceil(n/k);
        double sum=k*mul;
        ll l=1,r=sum;
        ll ans=1;
        // cout<<sum<<" ";
        while(l<=r) {
            ll mid=l+(r-l)/2;
            if(ceil(sum/mid)<=n) {
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
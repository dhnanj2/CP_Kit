// problem : https://codeforces.com/contest/1526/problem/C2

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
    // int t;
    // cin>>t;
    // while(t--) {
        int n;
        cin>>n;
        vector<ll> a(n,0);
        for(auto &i:a) cin>>i;
        multiset<ll> neg;
        ll ans=0,health=0;
        for(auto i:a) {
            if(!neg.empty() && health+i<0) {
                ll x=*neg.begin();
                if(x>i) continue;
                health -= x;
                neg.erase(neg.begin());
                ans--;
            }
            if(health+i>=0) {
                health+=i;
                if(i<0) neg.insert(i);
                ans++;
            }
            // cout<<health<<" ";
        }
        cout<<ans<<"\n";
    // }
    return 0;
}
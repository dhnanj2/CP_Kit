// problem : https://codeforces.com/problemset/problem/682/A

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
    int x,y;
    cin>>x>>y;
    ll rx[5]={ },ry[5]={ };
    ll ans=0;
    FOR(i,1,x+1,1) {
        rx[i%5]++;
    }
    FOR(i,1,y+1,1) {
        ry[i%5]++;
    }
    // print(rx);
    // print(ry);
    FOR(i,0,5,1) {
        if(!i) {
            ans+=rx[i]*ry[i];
            continue;
        }
        ans += (rx[i]*ry[5-i]);
    }
    cout<<ans;
    return 0;
}
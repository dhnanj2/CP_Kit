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
    int n,m;
    cin>>n>>m;
    vector<vector<short>> a(n,vector<short> (m,0));
    for(auto &i:a) {
        for(auto &j:i) cin>>j;
    } 
    int ans=0;
    FOR(i,0,m,1) {
        if(a[0][i]) ans=2;
    }
    FOR(i,0,m,1) {
        if(a[n-1][i]) ans=2;
    }
    FOR(i,0,n,1) {
        if(a[i][0]) ans=2;
    }
    FOR(i,0,n,1) {
        if(a[i][m-1]) ans=2;
    }
    if(!ans) ans=4;
    cout<<ans<<"\n";
    return 0;
}
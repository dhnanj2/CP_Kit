
// PROBLEM : https://www.codechef.com/problems/NUM239

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
    vector<int> pre(1e5+1,0);
    FOR(i,1,1e5+1,1) {
        auto s=to_string(i);
        pre[i]=pre[i-1];
        if(s.back()=='2' || s.back()=='3' || s.back()=='9') pre[i]++;
    }
    int t;
    cin>>t;
    while(t--) {
        int l,r;
        cin>>l>>r;
        int ans=pre[r]-pre[l-1];
        cout<<ans<<"\n";
    }
    return 0;
}
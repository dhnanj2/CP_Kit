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
    int n,q;
    cin>>n;
    vector<int> x(n,0);
    for(auto &i:x) cin>>i;
    cin>>q;
    vector<int> m(q,0);
    for(auto &i:m) cin>>i;
    sort(all(x));
    for(auto i:m){
        auto it=upper_bound(all(x),i);
        cout<<it-x.begin()<<"\n";
    }
    return 0;
}
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
    int s,n;
    cin>>s>>n;
    multiset<pair<int,int>> ms;
    FOR(i,0,n,1) {
        int x,y;
        cin>>x>>y;
        ms.emplace(x,y);
    }
    while(!ms.empty()) {
        auto it=ms.begin();
        if(s<=it->first) break;
        s+=it->second;
        ms.erase(it);
    }
    cout<<(ms.empty()?"YES":"NO");
    return 0;
}
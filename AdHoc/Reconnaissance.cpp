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
    int n,d;
    cin>>n>>d;
    vector<int> a(n,0);
    for(auto &i:a) cin>>i;
    sort(all(a));
    int cnt=0;
    FOR(i,0,n,1) {
        FOR(j,i+1,n,1) {
            if(a[j]-a[i]>d) break;
            cnt+=2;
        }
    }
    cout<<cnt;
    return 0;
}
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

// returns the no. of bits by which a and b differ
int diff(int a,int b) {
    int t=1,ans=0;
    FOR(i,1,21,1) {
        // cout<<(a&t)<<" "<<(b&t)<<"\n";
        if((a&t)!=(b&t)) ans++;
        t<<=1;
    }   
    return ans;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m+1,0);
    for(auto &i:a) cin>>i;
    int cnt=0;
    FOR(i,0,m,1) {
        // cout<<diff(a[m],a[i])<<" ";
        if(diff(a[m],a[i])<=k) cnt++;
    }
    cout<<cnt;
    return 0;
}
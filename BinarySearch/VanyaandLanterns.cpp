// problem : https://codeforces.com/problemset/problem/492/B
/*
Sort lanterns in non-decreasing order. Then we need to find maximal distance between two neighbour lanterns, let it be maxdist. 
Also we need to consider street bounds and count distances from outside lanterns to street bounds, it will be (a[0] - 0) and (l - a[n - 1]). 
The answer will be max(maxdist / 2, max(a[0] - 0, l - a[n - 1]))
*/
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

bool possible(vector<ll> &a, double d, ll len) {
    double l=a[0]-d , r=a[0]+d;
    if(l>0) return false;
    FOR(i,1,sz(a),1) {
        double l1=a[i]-d , r1=a[i]+d;
        // cout<<l1<<" "<<r1<<"\n";
        if(l1>r) return false;
        r=r1;
        l=l1;
    }
    return r>=len;
}

int main()
{
    ll n,len;
    cin>>n>>len;
    vector<ll> a(n,0);
    for(auto &i:a) cin>>i;
    sort(all(a));
    double str=max(a[0],len-a[n-1]);
    double gap=0;       
    FOR(i,1,n,1) {
        gap = max(gap,((double)a[i]-a[i-1]));
    }
    cout<<setprecision(11)<<fixed;
    double ans=max(gap/2,str);
    cout<<ans;
    return 0;
}
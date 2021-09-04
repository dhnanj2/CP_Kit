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
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(auto &i:a) cin>>i;
    int ans=0;
    FOR(i,0,n,1) {
        int cnt=1,mn=a[i];
        int j=i+1;
        while(j<n && a[j]<=mn) {
            mn=min(a[j],mn);
            j++;cnt++;
        }
        j=i-1;
        mn=a[i];
        while(j>=0 && a[j]<=mn) {
            mn=min(a[j],mn);
            j--;cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
// problem : https://codeforces.com/problemset/problem/1426/C

#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define print(v)    for(auto i:v) cout<<i<<" ";

#define pii pair<int,int>

#define ll long long 

#define int long long 

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

bool isPossible(int moves, int target) {
    int mx=moves/2+1;
    moves-=(mx-1);
    mx*=(moves+1);
    // return mx;
    if(mx>=target) return true;
    return false;
}

int_fast32_t main()
{
    int t; 
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int l=0,r=n,ans=n;
        while(l<=r) {
            int mid=(l+r)/2;
            if(isPossible(mid,n)) {
                ans=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }    
    return 0;
}
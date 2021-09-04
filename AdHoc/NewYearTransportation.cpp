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
    int n,t;
    cin>>n>>t;
    vector<int> a(n-1,0);
    for(auto &i:a) cin>>i;
    string ans="NO";
    int cur=1;
    while(cur<n) {
        cur += a[cur-1];
        if(cur==t) {
            ans="YES";
            break;
        }     
    }    
    cout<<ans;
    return 0;
}
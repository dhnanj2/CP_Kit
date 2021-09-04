// problem : https://codeforces.com/problemset/problem/158/B
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
    int s[4]={ };
    FOR(i,0,n,1) {
        int x;
        cin>>x;
        s[x-1]++;
    }
    int ans=s[3];
    int x=min(s[2],s[0]);
    ans+=x;
    s[2]-=x;
    s[0]-=x;
    ans += s[0]/4;
    s[0]%=4;
    if(s[0]==3) s[2]++ , s[0]=0;
    else if(s[0]==2) s[1]++ , s[0]=0;
    else if(s[0]==1) {
        s[2] ? s[2]-- : (s[1] ? s[1]-- : 0);
        ans++;
    }
    ans += s[1]/2;
    ans += s[1]%2;
    ans+=s[2];
    cout<<ans;
    return 0;
}
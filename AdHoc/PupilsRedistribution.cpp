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
    vector<int> b(n,0);
    unordered_map<int,int> ft;
    unordered_map<int,int> fa;
    for(auto &i:a) {
        cin>>i;
        ft[i]++;
        fa[i]++;
    }
    for(auto &i:b) {
        cin>>i;
        ft[i]++;
    }
    bool flg=false;
    int ans=0;
    for(auto i:ft) {
        if(i.S%2==1)  {
            flg=true;
            break;
        }
        ans += abs(i.S/2-fa[i.F]);
    }
    if(flg) cout<<-1;
    else {
        ans/=2;
        cout<<ans;
    }
    return 0;
}
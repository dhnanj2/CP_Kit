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
    int n,a,b;
    cin>>n>>a>>b;
    if(a*b<n) cout<<-1;
    else {
        vector<vector<int>> ans(a,vector<int>(b,0));
        int e=2,o=1;
        FOR(i,0,a,1) {
            FOR(j,0,b,1) {
                if((i+j)%2 && e<=n) {
                    ans[i][j] = e;                
                    e+=2;
                }else if((i+j)%2==0 && o<=n) {
                    ans[i][j]=o;
                    o+=2;
                } 
            }
        }
        for(auto i:ans) {
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
    }
    return 0;
}
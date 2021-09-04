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

void invert(char &c) {
    if(c=='1') c='0';
    else c='1';
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> grid(n);
        for(auto &i:grid) {
            cin>>i;
        } 
        int cnt=0;
        char c=grid[1][0];
        vector<pair<int,int>> ans;
        if(grid[0][1]!=grid[1][0]) {
            ans.emplace_back(1,2);
        }
        if(grid[n-1][n-2]!=grid[n-2][n-1]) {
            if(grid[n-1][n-2]==c) ans.emplace_back(n,n-1);
            else ans.emplace_back(n-1,n);
        }else if(grid[n-1][n-2]==c) {
                if(!ans.empty()) ans.pop_back();
                ans.emplace_back(2,1);
                if(grid[0][1]==c) ans.emplace_back(1,2);
        }
        cout<<sz(ans)<<"\n";
        for(auto i:ans) {
            cout<<i.F<<" "<<i.S<<"\n";
        }
    }
    return 0;
}
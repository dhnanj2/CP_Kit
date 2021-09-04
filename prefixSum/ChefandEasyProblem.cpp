
// PROBLEM : https://www.codechef.com/problems/XXOR

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
    int n,q;
    cin>>n>>q;
    vector<int> a(n,0);
    for(auto &i:a) cin>>i;
    vector<vector<int>> ones(n,vector<int> (32,0));
    FOR(i,0,32,1) {
        if(a[0]&(1<<i)) ones[0][i]=1;       
    }
    FOR(i,1,n,1) {
        FOR(j,0,32,1) {
            ones[i][j]=ones[i-1][j];
            if(a[i]&(1<<j)) ones[i][j]++;
            // cout<<ones[i][j]<<" ";
        }
        // cout<<endl;
    }
    while(q--) {
        int l,r;
        cin>>l>>r;
        int mid=(r-l+2)/2;
        auto x=0l;
        FOR(i,0,31,1) {
            int cnt = l>1 ? ones[r-1][i]-ones[l-2][i] : ones[r-1][i];
            // cout<<cnt<<" ";
            if(cnt<mid) x|=(1<<i);
        }
        // bitset<32> b(x);
        // cout<<b.to_string()<<"\n";
        cout<<x<<"\n";
    }
    return 0;
}
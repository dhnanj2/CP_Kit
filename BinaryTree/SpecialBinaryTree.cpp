// Problem : https://codeforces.com/problemset/problem/1490/D

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

void solve(vector<int> a,vector<int> &ans,int end,int st=0, int h=0) {
    if(st>=end) return ;
    int m=max_element(a.begin()+st,a.begin()+end)-a.begin();    
    ans[m]=h;
    solve(a,ans,m,st,h+1);
    solve(a,ans,end,m+1,h+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n,0),ans(n,0);
        for(auto &i:a) cin>>i;
        solve(a,ans,n);
        print(ans);
        cout<<"\n";
    }
    return 0;
}

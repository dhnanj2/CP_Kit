// Problem : https://codeforces.com/contest/1509/problem/B

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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n%3!=0 || s[0]=='M' || s[n-1]=='M') {
            cout<<"NO\n";
            continue;
        }
        int k=n/3;
        vector<int> t;
        bool flg=true;
        FOR(i,0,n,1) {
            if(s[i]=='T') t.pb(i);
        }
        reverse(all(t));
        FOR(i,0,n,1) {
            if(s[i]=='M' && !t.empty() && t.back()<i) t.pop_back();
            else if(s[i]=='M') {
                flg=false;
                break;
            }
        }
        if(!flg || sz(t)<k) cout<<"NO\n";
        else {
            FOR(i,0,n,1) {
                if(s[i]=='M' && !t.empty() && t.back()>i) t.pop_back();
                else if(s[i]=='M') {
                    flg=false;
                    break;
                }
            }   
            cout<<(flg && t.empty()?"YES":"NO")<<"\n";
        }
    }
    return 0;
}

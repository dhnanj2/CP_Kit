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
        vector<int> a(2*n,0);
        for(auto &i:a) {
            cin>>i;
        }
        vector<int> e,o;
        FOR(i,0,2*n,1) {
            if(a[i]%2) o.push_back(i);
            else e.push_back(i);
        }
        int x=n-1 , i=0;
        while(x>0 && i+1<sz(e)) {
            cout<<e[i]+1<<" "<<e[i+1]+1<<"\n";
            x--;i+=2;
        }
        i=0;
        while(x>0 && i+1<sz(o)) {
            cout<<o[i]+1<<" "<<o[i+1]+1<<"\n";
            x--;i+=2;
        }
    }
    return 0;
}
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

vector<int> factors(int n) {
    vector<int> f;
    for(int i=2;i*i<=n;i++) {
        while(n%i==0) {
            f.push_back(i);
            n/=i;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int a,b,k;
        cin>>a>>b>>k;
        if(b>a) swap(a,b);
        if(k==0) {
            cout<<(a==b?"YES":"NO")<<"\n";
        }else if(k==1) {
            cout<<(a%b==0 && a>b?"YES":"NO")<<"\n";
        }else {
            auto fa=factors(a),fb=factors(b);
            int m=sz(fa)+sz(fb);
            cout<<(k>=2 && k<=m?"YES":"NO")<<"\n";
        }
    }
    return 0;
}
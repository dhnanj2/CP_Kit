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
        vector<int> a(n,0);
        vector<int> e;
        vector<int> o;
        for(auto &i:a) {
            cin>>i;
            if(i%2) o.push_back(i);
            else e.push_back(i);
        }
        if(sz(e)%2!=sz(o)%2) cout<<"NO";
        else if(sz(e)%2==0) cout<<"YES";
        else {
            bool flg=false;
            FOR(i,0,sz(e),1) {
                FOR(j,0,sz(o),1) {
                    if(abs(e[i]-o[j])==1) {
                        flg=true;
                        break;
                    }
                }
            }
            cout<<(flg?"YES":"NO");
        }
        cout<<"\n";
    }
    return 0;
}
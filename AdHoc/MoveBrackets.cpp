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
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int op=0,ans=0;
        FOR(i,0,n,1) {
            if(s[i]=='(') op++;
            else {
                if(!op) {
                    s.erase(s.begin()+i);
                    s.push_back(')');
                    ans++;
                    i--;
                }
                else op--;
            }
        }
        cout<<ans<<"\n";
    }    
    return 0;
}
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
    int lucky[]={4,7,44,47,74,77,444,447,474,744,774,747,477,777};
    string ans="NO";
    FOR(i,0,14,1) {
        if(n%lucky[i]==0) {
            ans="YES";
            break;
        }
    }     
    cout<<ans;
    return 0;
}
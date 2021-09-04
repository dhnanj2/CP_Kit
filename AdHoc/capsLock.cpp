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

bool check(string s) {
    FOR(i,1,sz(s),1) {
        if(s[i]>=97) return false;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    if(check(s)) {
        for(auto &i:s) {
            if((int)i>=97) i-=32;
            else i+=32;
        }
    }
    cout<<s;
    return 0;
}
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

bool isBeautifull(string s) {
    FOR(i,1,sz(s),1) {
        if(s[i-1]==s[i]) return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        FOR(i,0,sz(s),1) {
            if(s[i]=='?') {
                if(i>0 && i<sz(s)-1) {
                    if(s[i-1]=='a') {
                        if(s[i+1]=='b') s[i]='c';
                        else if(s[i+1]=='c') s[i]='b';
                        else s[i]='b';
                    }
                    else if(s[i-1]=='b') {
                        if(s[i+1]=='a') s[i]='c';
                        else if(s[i+1]=='c') s[i]='a';
                        else s[i]='c';
                    }else {
                        if(s[i+1]=='a') s[i]='b';
                        else if(s[i+1]=='b') s[i]='a';
                        else s[i]='a';
                    }
                }else if(i==0) {
                    if(i<sz(s)-1)   {
                        if(s[i+1]=='a') s[i]='b';
                        else s[i]='a';
                    }else s[i]='a';
                }else {
                    if(s[i-1]=='a') s[i]='b';
                    else s[i]='a';
                }
            }
        }
        cout<<(isBeautifull(s)?s:"-1")<<"\n";
    }
    return 0;
}
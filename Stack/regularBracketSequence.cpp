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
    cin>>t>>ws;
    while(t--) {
        string s;
        cin>>s;
        stack<int> s1,s2;
        string ans="YES";
        FOR(i,0,sz(s),1)  {
            if(s[i]=='?') {
                s2.push(i);            
            }
            else if(s[i]=='(') s1.push(i);
            else {
                if(!s1.empty()) s1.pop();
                else if(!s2.empty()) s2.pop();
                else {
                    ans="NO";
                    break;
                }
            }
        }
        while(!s1.empty()) {
            if(!s2.empty() && s1.top()<s2.top()) {
                s1.pop();
                s2.pop();
            }else {
                ans="NO";
                break;
            }
        }
        if(ans=="YES" && sz(s2)%2!=0) ans="NO";
        cout<<ans<<"\n";
    }
    return 0;
}
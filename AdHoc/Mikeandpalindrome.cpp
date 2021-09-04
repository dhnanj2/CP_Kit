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

int isPalindrome(string &s) {
    int l=0,r=sz(s)-1;
    int cnt=0;
    while(l<r) {
        if(s[l++]!=s[r--]) cnt++;
    }
    if(sz(s)%2!=0 && !cnt) cnt=1;
    return cnt;
}

string solve(string s) {
    return isPalindrome(s)==1?"YES":"NO";
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}
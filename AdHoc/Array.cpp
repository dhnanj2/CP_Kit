// problem : https://codeforces.com/problemset/problem/300/A

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
    vector<int> s1,s2,s3;
    FOR(i,0,n,1) {
        int x;
        cin>>x;
        if(x>0) s1.push_back(x);
        else if(x<0) s2.push_back(x);
        else s3.push_back(x);
    }
    if(!sz(s1)) {
        s1.push_back(s2.back());
        s2.pop_back();
        s1.push_back(s2.back());
        s2.pop_back();
    }
    if(!(sz(s2)&1)) {
        s3.push_back(s2.back());
        s2.pop_back();
    }
    cout<<sz(s2)<<"\n";
    print(s2);
    cout<<"\n" << sz(s1)<<"\n";
    print(s1);
    cout<<"\n" << sz(s3)<<"\n";
    print(s3);
    return 0;
}
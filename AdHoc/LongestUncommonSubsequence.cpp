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
/*
If the strings are the same, Any subsequence of a is indeed a subsequence of b so the answer is "-1", Otherwise the longer string can't be a subsequence of the other (If they are equal in length and aren't the same,
No one can be a subsequence of the other) so the answer is maximum of their lengths.
*/
int main()
{
    string a,b;
    cin>>a>>ws>>b;
    if(a==b) cout<<-1;
    else {
        cout<<max(sz(a),sz(b));
    }
    return 0;
}
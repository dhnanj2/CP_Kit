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
    int n,k;
    cin>>n>>k;
    int  moves=0;
    if(k==1 || k==n) {
        moves=n-1;
    }else if(k<=(n+1)/2) {
        moves = k-1;
        moves += (k);
        moves+=(n-k-1);
    }else {
        moves = (n-k);
        moves += (n-k+1);
        moves += (k-1-1);
    }
    moves += 3;
    moves += (n-1)*2;
    cout<<moves<<"\n";
    return 0;
}
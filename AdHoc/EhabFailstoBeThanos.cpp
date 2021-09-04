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
    vector<int> a(2*n,0);
    for(auto &i:a) cin>>i;
    bool flg=false;
    sort(all(a));
    ll sum1 = accumulate(a.begin(),a.begin()+n,0ll);
    ll sum2 = accumulate(a.begin()+n,a.end(),0ll);
    if(sum1==sum2) cout<<-1<<"\n";
    else {
        print(a);
    }
    return 0;
}
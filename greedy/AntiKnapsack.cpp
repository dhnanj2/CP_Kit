/*
Let's notice that we can take all numbers k+1,k+2…n, because every one of them is greater than k, and sum of any number from k+1,k+2…n and any number from 1,2…n also is greater than k. 
Let's also take numbers from ⌈k2⌉ to k−1 inclusive. 
Notice that the sum of any two chosen numbers is already greater than k,
and no chosen number is equal to k, therefore such set is correct. 
It contains (n−k)+(k−⌈k2⌉)=n−⌈k2⌉ numbers.
*/
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
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> ans;
        int i=ceil((float)k/2);
        while(i<k && i<=n) {
            ans.pb(i++);
        }
        FOR(i,k+1,n+1,1) {
            ans.pb(i);
        }
        cout<<sz(ans)<<"\n";
        print(ans);
        cout<<'\n';
    }
    return 0;
}
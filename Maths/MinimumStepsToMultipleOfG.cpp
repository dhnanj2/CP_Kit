/*
problem : given integers 'g' & 'b' determine the min steps to make 'b' a multiple of 'g'. 
          In one step u can either increase or decrease 'b' by one.
          For eg: b=5 , g=3 then ans=1(make b=6) 
                  b=12, g=6 then ans=0 
*/
/*
There are two ways to do so − decrease b to the largest multiple of g less than or equal to b or increase b to the smallest multiple of g greater than b. 
The number of operations required to do so are bmodg and g−bmodg respectively. We will obviously choose the minimum of the two.
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define rall(c) (c).rbegin(), (c).rend()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define print(v)    for(auto i:v) cout<<i<<" ";

#define pii pair<int,int>

#define author dhnanj

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
        ll b,g;
        cin>>b>>g;
        cout<<min(b%g,g-b%g);
    }
    return 0;
}
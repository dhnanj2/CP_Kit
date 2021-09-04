/*
You are given two positive integer sequences a1,…,an and b1,…,bm. For each j=1,…,m find the greatest common divisor of a1+bj,…,an+bj.

Input
The first line contains two integers n and m (1≤n,m≤2⋅10^5).

The second line contains n integers a1,…,an (1≤ai≤10^18).

The third line contains m integers b1,…,bm (1≤bj≤10^18).

Output
Print m integers. The j-th of them should be equal to GCD(a1+bj,…,an+bj).

Example
input
4 4
1 25 121 169
1 2 7 23
output
2 3 8 24
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define rall(c) (c).rbegin(), (c).rend()

#define sz(x) (ll)(x).size()

#define FOR(i, a, b, s) for (ll i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define print(v)    for(auto i:v) cout<<i<<" ";

#define pii pair<int,int>

#define author dhnanj

#define ll long long

#define pb push_back

#define S second

#define F first

const ll MOD = 1e9+7;

static const auto __optimize__ = []() {

std::ios::sync_with_stdio(false);

std::cin.tie(nullptr);

std::cout.tie(nullptr);

return 0;

}();
/*
From basic properties of GCD we know that GCD(x,y)=GCD(x−y,y). 
The same applies for multiple arguments: GCD(x,y,z,…)=GCD(x−y,y,z,…). Let's use this for GCD(a1+bj,…,an+bj) and subtract a1+bj from all other arguments: GCD(a1+bj,…,an+bj)=GCD(a1+bj,a2−a1,…,an−a1).
If we find G=GCD(a2−a1,…,an−a1), then any answer can be found as GCD(a1+bj,G). Note that we have to assume that GCD of an empty set is 0, and GCD(x,0)=x for any x, since 0 is the only number divisible by any other number.
*/
int main()
{
	// int t;
	// cin>>t;
	// while(t--) {
		int n,m;
		cin>>n>>m;
		vector<ll> a(n,0),b(m,0),ans(m,0);
		for(auto &i:a)cin>>i;
		for(auto &i:b)cin>>i;
		ll g=0ll;
		FOR(i,1,n,1) {
			g=abs(__gcd(g,a[i]-a[0]));
		}
		FOR(i,0,m,1) {
			ans[i]=abs(__gcd(a[0]+b[i],g));
		}
		print(ans);
		cout<<'\n';
	// }
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x.size())

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


vector<bool> SieveOfEratosthenes(int n) 
{ 
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	vector<bool> prime(n+1,1);

	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 
	return prime;
}
/*
    approach :-
    out of 4 factors, 2 factors are 1, and the number itself, which always exist therefore we just need to search for the remaining two factors.
    the first one of them can be obtained by searching for a prime number which is atleast d far from 1.let this no. be a.
    the second no. can be obtained by searching for a no. which is atleast d distance from a.let this no. be b.
    the required ans is a*b;
*/
int main()
{
    auto prime=SieveOfEratosthenes(1000000);
    int t;
    cin>>t;
    while (t--)
    {
        int d;
        cin>>d;
        int i=2;
        while (i<1e9) {
            if(i>=d+1 && prime[i]) break;
            i++;
        }
        ll a=i;
        i=a+1;
        while (i<1e9) {
            if(i-a>=d && prime[i]) break;
            i++;
        }
        ll b=i;
        ll ans=a*b;
        cout<<ans<<"\n";
    }    
    return 0;
}
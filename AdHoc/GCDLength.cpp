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

int main()
{
    vector<int> z(10,0);   //z[i]=smallest prime of length i
    z[1]=2;
    FOR(len,2,10,1) {
        int x=stoi(string(len,'1'));
        z[len]=x;
    }
    // for(auto i:z) cout<<i<<" ";
    int t;
    cin>>t;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        int x=z[c],y=z[c];
        while(log10(x)+1<a) x*=2;
        while(log10(y)+1<b) y*=3;
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}
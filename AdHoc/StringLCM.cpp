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

int *pre_kmp(string pattern)
{
	int size = pattern.size();
	int *pie=new int [size];
	pie[0] = 0;
	int k=0;
	for(int i=1;i<size;i++)
	{
		while(k>0 && pattern[k] != pattern[i] )
		{
			k=pie[k-1];
		}
		if( pattern[k] == pattern[i] )
		{
			k=k+1;
		}
		pie[i]=k;
	}
	
	return pie;
}

// Searching , overall Time : O(N+M) , space : O(M)
bool kmp(string text,string pattern)
{
	int* pie=pre_kmp(pattern);
	// for(int i=0;i<pattern.size();i++) cout<<pie[i];
	int matched_pos=0;
	for(int current=0; current< text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.length()) )
		{
			// cout<<"Found at : "<<current - (pattern.length() -1 )<<"\n";
	        delete[] pie;	
            return true;
			matched_pos = pie[matched_pos-1];
		}
	}
    return false;
}

int lcm(int a, int b) {
    return (a*b)/__gcd(a,b);
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        string s,t;
        cin>>s>>ws>>t;
        if(sz(s)<sz(t)) swap(s,t) ;
        if(kmp(s,t)) {
            int x=lcm(sz(s),sz(t));
            string s1,t1;
            while(sz(s1)<x) {
                s1+=s;
            }
            while(sz(t1)<x) {
                t1+=t;
            }
            // cout<<s<<" "<<t<<"\n";
            if(s1==t1) cout<<s1<<"\n";
            else cout<<-1<<"\n";
        }else {
            cout<<-1<<"\n";
        }
    }
    return 0;
}
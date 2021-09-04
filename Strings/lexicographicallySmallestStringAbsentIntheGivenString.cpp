// https://codeforces.com/contest/1535/problem/C

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
	int *p=new int [size];
	p[0] = 0;
	int k=0;
	for(int i=1;i<size;i++)
	{
		while(k>0 && pattern[k] != pattern[i] )
		{
			k=p[k-1];
		}
		if( pattern[k] == pattern[i] )
		{
			k=k+1;
		}
		p[i]=k;
	}
	return p;
}

// Searching , overall Time : O(N+M) , space : O(M)
bool kmp(string text,string pattern)
{
	int matched_pos=0;
	int *pie=pre_kmp(pattern);
	for(int current=0; current< text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.length()) )
		{
			return true;
			matched_pos = pie[matched_pos-1];
		}
	}
	delete[] pie;	
    return false;
}

/*
Let’s brute force check all substrings of length <= 3 and print the lexicographically smallest one that doesn’t appear as a substring in the input. 
We can guarantee that we will come across the answer due to the pigeonhole principle. 
There are at most n+n−1+n−2=3n−3 possible substrings of length 3 or shorter in the input. 
There exist 26+262+263=18278 total substrings of length 3 or shorter. 
It is impossible for the input to contain all 18278 substrings, as 3n−3<18278 for n≤1000.
Final runtime looks something like O(18278n) or O(n) depending on how you implement substring checking.
*/

// for a given length we generate strings [aa...]n, [aa...b]n , .....[baa...]n, [bba...]n.....[zz...]n
void helper(string &t,string &ans,const string &s,int id=0) {
	if(id>=t.size()) return;
	for(char c='a';c<='z';c++) {
		t[id]=c;
		helper(t,ans,s,id+1);
		if(!kmp(s,t)) {
			ans=t;
			return;
		}	
	}
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
	    cin>>s;
        string ans,t;       
		// first we fix a length of the string 
        FOR(len,1,n+1,1) {
			t.resize(len);
			helper(t,ans,s);
            if(!ans.empty()) break;
        }
        if(!ans.empty()) cout<<ans<<"\n";
        else cout<<s<<"a"<<"\n";
    }
    return 0;
}
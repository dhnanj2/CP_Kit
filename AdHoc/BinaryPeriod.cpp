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

// Returns true if str1[] is a 
// subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(string str1, string str2)
{
    int m=str1.size();
    int n=str2.size();

    int j = 0; // For index of str1 (or subsequence
    
    // Traverse str2 and str1, and 
    // compare current character
    // of str2 with first unmatched char 
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == m);
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        string ans;
        if(isSubSequence("10",s)) {
            int x=sz(s);
            while(x--) {
                ans+="10";
            }
        }else if(isSubSequence("01",s)) {
            int x=sz(s);
            while(x--) {
                ans+="01";
            }
        }else {
            ans=s;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
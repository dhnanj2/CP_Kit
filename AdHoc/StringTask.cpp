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
                            // AC
bool vowel(char c) {
    if(c<97) c+=32;
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

int main()
{
    string s;
    cin>>s;
    FOR(i,0,s.size(),1) {
        // cout<<s<<"\n";
        if(vowel(s[i])) {
            s.erase(s.begin()+i);
            i--;
        }else{
            if(s[i]<97) s[i]+=32;
            s.insert(s.begin()+i,'.');
            i++;
        }    
    }
    cout<<s;
    return 0;
}
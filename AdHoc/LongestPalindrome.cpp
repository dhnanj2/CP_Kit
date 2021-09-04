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

bool isPalindrome(string s) {
    int i=0,j=sz(s)-1;
    while(i<j) {
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}

struct cmp {
    bool operator()(string l,string r) {
        return sz(l)>sz(r);
    }
};

int main()
{
    int n,m;
    cin>>n>>m; 
    vector<string> a;  
    string ans;
    FOR(i,0,n,1) {
        string s;
        cin>>s;
        a.push_back(s);
    }
    list<string> l;
    string p;
    for(auto &i:a) {
        if(!isPalindrome(i)) {
            auto t=i;
            reverse(all(t));
            auto it=find(all(a),t);
            if(it!=a.end()) {
                l.push_back(t);
                l.push_front(i);
            }
            i.clear();
        }else if(sz(i)>sz(p)) p=i; 
    }
    // print(l);
    // cout<<endl;
    int x=sz(l)/2;
    while(sz(l)!=x) {
        ans+=l.front();
        l.pop_front();
    }
    ans+=p;
    while(sz(l)) {
        ans+=l.front();
        l.pop_front();
    }
    cout<<sz(ans)<<"\n";
    cout<<ans<<"\n";
    return 0;
}
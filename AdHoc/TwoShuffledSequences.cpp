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
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(auto &i:a) cin>>i;
    set<int,greater<int>> s;
    unordered_map<int,int> m;
    string ans="YES";
    FOR(i,0,sz(a),1) {
        // cout<<a[i]<<" ";
        if(m[a[i]]>=2) {
            ans = "NO";
            break;
        }else if(m[a[i]]==1) {
            s.insert(a[i]);
            m[a[i]]++;
            a.erase(a.begin()+i);
            i--;
        }else m[a[i]]++;
    }
    cout<<ans<<"\n";;
    if(ans=="YES") {
        sort(all(a));
        cout<<sz(a)<<"\n";
        print(a);
        cout<<"\n";
        cout<<sz(s)<<"\n";
        print(s);
        cout<<"\n";
    }
    return 0;
}
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

void rotLeft(vector<int> &a, int d) {
    // shiftng 'd' units left = shifting a.size()-d units right
    int k=a.size()-d;
    vector<int> b(a.size(),0);
    for (size_t i = 0; i < a.size(); i++)
    {
        int new_pos= (i+k)%a.size();
        b[new_pos] = a[i];
    }
    a=b;
}
bool check(vector<int> a) {
    unordered_set<int> s;
    FOR(i,0,sz(a),1) {
        int x=i-a[i];
        if(s.find(x)!=s.end()) return true;
        s.insert(x);
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n,0);
        for(auto &i:a) cin>>i;
        sort(all(a),greater<int>());
        print(a);
        cout<<"\n";
    }
    return 0;
}
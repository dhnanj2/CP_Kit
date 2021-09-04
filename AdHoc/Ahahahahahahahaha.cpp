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

int check(vector<int> &a) {
    int id=-1;
    FOR(i,1,sz(a),2) {
        if(a[i]-a[i-1]!=0) {
            id = a[i] ? i : i-1;
            break;
        }
    }
    return id;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n,0);
        int cnt0=0,cnt1=0;
        for(auto &i:a) {
            cin>>i;
            if(i) cnt1++;
            cnt0++;
        }
        if(cnt1<=n/2) {
            FOR(i,0,sz(a),1) {
                if(a[i]) {
                    a.erase(a.begin()+i--);
                }
            }
        }else {
            FOR(i,0,sz(a),1) {
                if(!a[i]) {
                    a.erase(a.begin()+i--);
                }
            }
            if(cnt1&1) a.pop_back();
        }
        cout<<sz(a)<<"\n";
        print(a);
        cout<<"\n";
    }
    return 0;
}
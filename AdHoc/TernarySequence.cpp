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
    int t;
    cin>>t;
    while(t--) {
        int x1,y1,z1;
        cin>>x1>>y1>>z1;
        int x2,y2,z2;
        cin>>x2>>y2>>z2;
        ll sum = 0;
        int a=min(y2,z1);
        y2 -= a;
        z1 -= a;
        sum += a*2;
        a=min(z2,z1);
        z1-=a; 
        z2-=a; 
        a=min(y2,y1);
        y1 -= a;
        y2 -= a;
        a=min(y1,x2);
        y1-=a;
        x2-=a;
        a=min(z2,x1);
        z2-=a;
        x1-=a;
        if(y1==z2) sum -= y1*2;
        cout<<sum<<"\n";
    }
    return 0;
}
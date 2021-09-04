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

void col(int n,int col,int flg,int skip=0) {
    if(flg>0) {
        FOR(i,1,n+1,1) {
            if(i!=skip) cout<<i<<" "<<col<<"\n";
        }
    }else {
        FOR(i,n,0,-1) {
            if(i!=skip) cout<<i<<" "<<col<<"\n";
        }
    }
}

int main()
{
    int n,m,sx,sy;
    cin>>n>>m>>sx>>sy;
    cout<<sx<<" "<<sy<<"\n";
    cout<<sx<<" "<<1<<"\n";
    col(n,1,1,sx);       
    int flg=-1;
    FOR(i,2,sy,1) {
        col(n,i,flg);
        flg*=-1;
    }
    col(n,sy,flg,sx);       
    FOR(i,sy+1,m+1,1) {
        flg*=-1;
        col(n,i,flg);
    }
    return 0;
}
// problem : https://codeforces.com/contest/1526/problem/B

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

int gcd(int a, int b, int &x, int &y) {
    if(!b) {
        x=1,y=0; // different values of y will produce different solutions of the same eqn which are all correct
        return a;
    }    
    int x1,y1;
    int g=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}

void solveforxy(int a, int b, int c,int &x, int &y) {
    if(!b && !a) return;
    int x1,y1;
    int g=gcd(a,b,x1,y1);
    if(c%g!=0) return ;
    x=x1*(c/g);
    y=y1*(c/g);
}
/*
    all the number of given type and >111 can be formed using just 11 and 111 
    therefore we need to find the +ve solutions the LDE:-
        11x+111y=n 
*/
int main()
{
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        int x=0,y=0;
        solveforxy(11,111,n,x,y);
        if(x<0) {
            int k=ceil((float)abs(x)/111);
            if(y-k*11>=0) cout<<"Yes\n";
            else cout<<"No\n";
        }else if(y<0) {
            int k=ceil((float)y/11);
            if(x+k*111>=0) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"Yes\n";
    }
    return 0;
}
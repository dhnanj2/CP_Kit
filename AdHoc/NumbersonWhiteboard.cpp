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

/*
It's easy to see that we can't get the result less than 2, because, if we merge two positive numbers, and at least one of them is 2 or greater, the new number is always greater than 1. So we can't get rid of all numbers greater than 1.
To always achieve 2, we can use a greedy algorithm: always merge two maximum numbers. During the first step, we merge n and n−1, get n; then we merge n and n−2, get n−1; then we merge n−1 and n−3, get n−2; and it's easy to see that the last operation is merging 3 and 1, so the result is 2.
*here round means : ceil()
*/
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a;
        FOR(i,1,n+1,1) a.push_back(i);
        cout<<2<<"\n";
        while(a.size()>1) {
            float x=a.back();
            cout<<x<<" ";
            a.pop_back();
            cout<<a.back()<<'\n';
            a[sz(a)-1]=ceil((x+a.back())/2);
        }
    }
    return 0;
}
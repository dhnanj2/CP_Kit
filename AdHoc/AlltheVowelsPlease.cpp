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

// Reversing Method, Time:O(N), space:O(1);
string rotateArr(string arr, int d){
    int n = sz(arr);
    // reverse the subarray arr[0...d]
    reverse(arr.begin(),arr.begin()+d);
    // reverse the subarray arr.begin()[d+1...n]
    reverse(arr.begin()+d,arr.begin()+n);
    // reverse the whole array
    reverse(arr.begin(),arr.begin()+n);
    return arr;
}

int main()
{
    int k;
    cin>>k;
    int n=0,m=0;
    for(int i=5;i*i<=k;i++) {
        if(k%i==0 && k/i>=5) {
            n=i , m=k/i;
            break;
        }
    }
    if(n && m) {
        string t="aeiou" , ans;
        FOR(i,0,n,1) {
            FOR(j,0,m,1) {
                ans.push_back(t[(i+j)%5]);
            }
        }
        cout<<ans;
    }else cout<<-1;
    return 0;
}
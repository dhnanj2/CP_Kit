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
We claim the answer is NO if and only if the elements are pairwise distinct.
If any element has two occurrences, we can trivially select them as the two subarrays. Otherwise, since all elements are distinct, choosing a subarray is the same as choosing the set bits of a 109 digit long binary number. 
Since every number has a unique binary representation, no two subarrays can have the same sum.
*/

int main()
{
    int  t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> b(n,0);
        for(auto &i:b) cin>>i;
        string ans="NO";
        unordered_set<int> s;
        for(auto i:b) {
            if(!s.insert(i).second) {
                ans="YES";
                break;
            } 
        }
        cout<<ans<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

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
    int t=0;
    cin>>t;
    while (t--)
    {
        int n=0 , x=0;
        cin>>n>>x;
        vector<int> a(n,0);
        for(auto &i:a) {
            cin>>i;
        }
        vector<int> ans;
        int cur=0 , can_go_till=x;
        while (cur+can_go_till<=n)
        {
            int j=cur , next=cur;
            while(j<n && j-cur<=can_go_till) {
                if(a[j]>a[next])
                    next = j;
                j++;
            }
            can_go_till -= (next-cur);
            can_go_till += a[next];
            ans.push_back(next+1);
            cur = next;
        }
        cout<<ans.size()<<"\n";
        for(auto i:ans) 
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
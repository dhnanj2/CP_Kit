// Problem : https://codeforces.com/problemset/problem/1490/D
 
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
 
template<typename T> 
class ST {
 
    T *rng_mx_seg,  // store segment tree which answers the range max queries
    *rng_mn_seg,    // store segment tree which answers the range min queries
    *rng_sum_seg,   // store segment tree which answers the range sum queries
    *rng_mul_seg;   // store segment tree which answers the range multiply queries
    
    void build(vector<T> &ar,int n, int low, int high) {
        if(low==high) {
            seg[n]=ar[low];
            // cout<<low<<" "<<high<<" "<<seg[n]<<"\n";
            return;
        }
        int mid = (low+high)/2;
        build(2*n+1,low,mid);
        build(2*n+2,mid+1,high);
        seg[n] = seg[2*n+1] + seg[2*n+2];
        // cout<<low<<" "<<high<<" "<<seg[n]<<"\n";
    }
 
 
    public :

        // MF to display the segment tree
        void disp() {
            FOR(i,0,4*size,1) cout<<seg[i]<<" ";
        }


        ST(vector<T> a) {
            size = a.size();
            ar=new T[size];
            seg=new T[4*size];
            for(int i=0;i<size;i++) ar[i]=a[i];
            build(0,0,size-1);
        }    

        void update(int id,T val,int low=0,int high=INT_MAX, int n=0) {
            if(high==INT_MAX) high=size-1;
            if(low>high) return;
            if(low==high) {
                ar[id]=seg[n]=val; 
                return;
            }
            int mid=(low+high)/2;
            if(mid>=id) update(id,val,low,mid,2*n+1);
            else update(id,val,mid+1,high,2*n+2);
            seg[n]=seg[2*n+1]+seg[2*n+2];
        }
 
        T query(int rl, int rr, int low=0, int high=INT_MAX, int id=0) {
            if(low>high) return 0;
            if(high==INT_MAX) high=size-1;
            // complete overlap
            if(rl<=low && rr>=high) return seg[id];
            // no overlap
            if(rl>high || rr<low) return 0;
            int mid=(low+high)/2;
            return query(rl,rr,low,mid,2*id+1) + query(rl,rr,mid+1,high,2*id+2);
        }
 
        ~ST() {
            delete[] ar;
            delete[] seg;
        }
};
 
int main()
{
    int n,q;
    cin>>n>>q;
    vector<ll> a(n,0);
    for(auto &i:a) cin>>i;
    ST<ll> t(a);
    while(q--) {
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1) t.update(a-1,b);
        else cout<<t.query(a-1,b-1)<<"\n";
    }
    return 0;
}
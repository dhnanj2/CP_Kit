#include<bits/stdc++.h>

using namespace std;

vector<int> factors(int n) {
    vector<int> f;
    for(int i=2;i*i<=n;i++) {
        while(n%i==0) {
            f.push_back(i);
            n/=i;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}

int main()
{
    auto v=factors(36);
    for(auto i:v) cout<<i<<" ";
    return 0;
}
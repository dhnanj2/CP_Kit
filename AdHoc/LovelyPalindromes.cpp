#include<bits/stdc++.h>

using namespace std;


int main()
{
    string n;
    cin>>n;
    string t=n;
    reverse(t.begin(),t.end());
    n+=t;
    cout<<n;
    return 0;
}
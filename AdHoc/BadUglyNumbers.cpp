#include<bits/stdc++.h>

using namespace std;
/*
If n=1, no solution exists.

Otherwise, if n≥2, the number 233…3¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ (n digits) satisfies all conditions, because it is not divisible by 2 and 3.
*/
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n==1) {
            cout<<-1<<"\n";
        }else {
            string ans;
            ans.push_back('2');
            while(ans.size()!=n) ans.push_back('3');
            cout<<ans<<"\n";
        }
    }
    return 0;
}
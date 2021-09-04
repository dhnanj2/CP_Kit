/*
In this problem it is enough to simply paint the upper left corner white and all the others black for any size of the board Like this:
And there are W=1 (cell with coordinates {1,1}) and B=2 (cells with coordinates {1,2} and {2,1}).
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<string> ans(n,string(m,'B'));
        ans[0][0]='W';
        for(auto i:ans){
            cout<<i<<"\n";
        }
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> z(10,0);   //z[i]=smallest prime of length i
    z[1]=2;
    for(int len=2;len<10;len++) {
        int x=stoi(string(len,'1'));
        z[len]=x;
    }
    return 0;
}
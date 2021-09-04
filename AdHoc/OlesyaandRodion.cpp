/*
Your task is: given the n and t print an integer strictly larger than zero consisting of n digits that is divisible by t. 
If such number doesn't exist, print  - 1.
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    if(t==10) {
        if(n>1) {
            string ans(n-1,'1');
            ans.push_back('0'); 
            cout<<ans;      
        }
        else cout<<-1;
    }else {
        string ans; 
        while(ans.size()<n) {
            ans.push_back((char)(t+48));
        }
        cout<<ans;
    }
    return 0;
}
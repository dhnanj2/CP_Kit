/*
Given a big number ‘num’ represented as string and an integer x, find value of “num % x” or “num mod x”. Output is expected as an integer.
*/
/*
The idea is to process all digits one by one and use the property that xy (mod a) ≡ ((x (mod a) * y) (mod a)). Below is the implementation.
*/
#include<bits/stdc++.h>

using namespace std;

int mod(string num, int a)
{
    // Initialize result
    int res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;
 
    return res;
}

int main()
{
    cout<<mod("12345",7);
    return 0;
}
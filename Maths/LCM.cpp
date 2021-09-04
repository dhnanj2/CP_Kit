// Find the LCM of 2 numbers
/* 
    An efficient solution is based on the below formula for LCM of two numbers ‘a’ and ‘b’. 
    a x b = LCM(a, b) * GCD (a, b)
    LCM(a, b) = (a x b) / GCD(a, b)
*/

#include<bits/stdc++.h>

using namespace std;

// time:O(long(min(a,b))) {due to gcd operatoin}, space:O(1)
int LCM(int a, int b,int c) {
    int x=(a*b)/__gcd(a,b);
    return (x*c)/__gcd(x,c);
}

int main()
{
    cout<<LCM(42,20,76);
    return 0;
}
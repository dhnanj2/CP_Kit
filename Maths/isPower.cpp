#include<bits/stdc++.h>

using namespace std;

bool isPower(ll x, ll y)
{
    // logarithm function to calculate value
    ll res1 = log(y) / log(x);
    double res2 = log(y) / log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}

int main()
{

    return 0;
}
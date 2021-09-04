/*
                                            Basic Euclidean Algorithm for HCF
The Euclidean algorithm is based on the below facts:
If we subtract the smaller number from larger (we reduce larger number), GCD doesn't change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide the smaller number, the algorithm stops when the remainder is found to be 0.

Below is the recursive function for finding GCD using Euclidean Algorithm:

Time Complexity: O(log(min(a, b)))

*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int A,int B)
{
    int a=min(A,B);
    int b=max(A,B);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    cout<<gcd(  24,6);
    return 0;
}
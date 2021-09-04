/*
Problem 2: Given a number N, find the most significant set bit in the given number.

Examples:
Input : N = 10
Output : 8
Binary representation of 10 is 1010
The most significant bit corresponds
to decimal number 8.

Input : N = 18
Output : 16
*/
/*
Bitwise Solution: The most-significant bit in binary representation of a number is the highest ordered bit, that is it is the bit-position with highest value.

One of the solution is first find the bit-position corresponding to the MSB in the given number, this can be done by calculating logarithm base 2 of the given number, i.e., log2(N) gives the position of the MSB in N.

Once, we know the position of the MSB, calculate the value corresponding to it by raising 2 by the power of calculated position. That is, value = 2log2(N).
*/

#include<bits/stdc++.h>

using namespace std;

// time : O(logN) ,space :O(1)
int log2(int x) 
{ 
    if(x<=0) return INT_MIN;
    int res = 0; 
    while (x >>= 1) 
        res++; 
    return res; 
} 

// returns the position(0 based) of most significant set bit in int 'x'
// time : O(logN) ,space:O(1)
int MSSB(int x) {
    return log2(x);
}

int main()
{
    cout<<MSSB(2);
    return 0;
}
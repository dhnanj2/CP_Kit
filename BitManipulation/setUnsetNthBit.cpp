/*
How to set a bit in the number 'num' : If we want to set a bit at nth position in number 'num' ,it can be done using 'OR' operator( | ).
First we left shift '1' to n position via (1 << n)
Then, use 'OR' operator to set bit at that position.'OR' operator is used because it will set the bit even if the bit is unset previously in binary representation of number 'num'.

How to unset/clear a bit at n'th position in the number 'num' :
Suppose we want to unset a bit at nth position in number 'num' then we have to do this with the help of 'AND' (&) operator.

First we left shift '1' to n position via (1 << n) than we use bitwise NOT operator '~' to unset this shifted '1'.
Now after clearing this left shifted '1' i.e making it to '0' we will 'AND'(&) with the number 'num' that will unset bit at nth position position.
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(1)
void setNthBit(unsigned int &x, int n) {
    x|=(1ul<<n);
}

// time : O(1)
void unsetNthBit(unsigned int &x, int n) {
    x&=(~(1ul<<n));
}

int main()
{
    unsigned int x=1ul;
    setNthBit(x,2);
    cout<<x;
    unsetNthBit(x,2);
    cout<<x;
    return 0;
}
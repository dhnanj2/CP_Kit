/*
Checking if bit at nth position is set or unset:
It is quite easily doable using 'AND' operator.

Left shift '1' to given position and then 'AND'('&').
If the result of the AND operation is 1 then the bit at nth position is set otherwise it is unset.
*/
#include<bits/stdc++.h>

using namespace std;

bool isSetNthBit(int x,int n) {
    return x&(1<<n);
}

int main()
{
    cout<<isSetNthBit(5,10);
    return 0;
}
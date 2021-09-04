/*
Toggling a bit at nth position : Toggling means to turn bit 'on'(1) if it was 'off'(0) and to turn 'off'(0) if it was 'on'(1) previously.We will be using 'XOR' operator here which is this '^'. The reason behind 'XOR' operator is because of its properties.
Properties of 'XOR' operator.
1^1 = 0
0^0 = 0
1^0 = 1
0^1 = 1
If two bits are different then 'XOR' operator returns a set bit(1) else it returns an unset bit(0).
*/
#include<bits/stdc++.h>

using namespace std;

void toggleNthBit(int &x, int n) {
    n^=(1<<n);
}

int main()
{
    
    return 0;
}
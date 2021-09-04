#include<bits/stdc++.h>

using namespace std;

//Function to find the first position with different bits.
// time : O(max(log m, log n)) ,space: O(1);
int posOfRightMostDiffBit(int m, int n)
{
    int pos=1;
    while((m&1)==(n&1)) {
        m>>=1;
        n>>=1;
        pos++;
    }
    return pos;
}

int main()
{

    return 0;
}
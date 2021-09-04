/*
Problem 1: Given a number N, the task is to check whether the given number is a power of 2 or not.

For Example:
Input : N = 4
Output : Yes
22 = 4

Input : N = 7
Output : No

Input : N = 32
Output : Yes
25 = 32
*/

/*
Bitwise Solution: If we subtract a number which is a power of 2 1 then all of it's unset bits after the only set bit become set; and the set bit become unset.

For example, consider 4 ( Binary representation: 100) and 16(Binary representation: 10000), we get following after subtracting 1 from them:
3 –> 011
15 –> 01111
You can clearly see that bitwise-AND(&) of 4 and 3 gives zero, similarly 16 and 15 also gives zero.

So, if a number N is a power of 2 then bitwise-AND(&) of N and N-1 will be zero. We can say that N is a power of 2 or not based on the value of N&(N-1).
*/
#include<bits/stdc++.h>

using namespace std;

bool isPowerofTwo(int n) {
    if(!n) return 0;
    if(n<0) n*=-1;
    return !((n)&(n-1));
}

int main()
{
    cout<<isPowerofTwo(4);
    cout<<isPowerofTwo(1);
    return 0;
}
/*
Flipping the bits of a number: It can be done by a simple way, just simply subtract the number from the value obtained when all the bits are equal to 1 .
For example:
Number : Given Number
Value  : A number with all bits set in given number.
Flipped number = Value – Number.

Example : 
Number = 23,
Binary form: 10111;
After flipping digits number will be: 01000;
Value: 11111 = 31;
*/
/*
                                            LEMMA
    obesring the pattern :-
    0->000
    1->001
    2->010
    3->011
    4->100
    5->101
    6->110
    7->111
    0 is flipped version of 7
    1 is flipped version of 6
    2 is flipped version of 5
    .
    .
    .
    therefore, for a n bits number x . its flipped version is 2^k - 1 - x
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

// time : O(LogN) , N-> no. of set bits in n
// flipps all the bits after MSSB including MSSB
void flipp(int &x) {
    // find position of the most significant set bit of 'x'
    int pos=MSSB(x);
    // obtain the bit with all its bits set till pos;
    int val=pow(2,pos+1)-1;
    // subtract x from val
    x = val-x;
}

int main()
{
    int x=8;
    flipp(x);
    cout<<x;
    return 0;
}
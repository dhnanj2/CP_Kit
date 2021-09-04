/*
Given a number as string(n) , find the remainder of the number whe it is divided by 7
You only need to complete the function remainderwith7() that takes string n as parameter and returns an integer which denotes the remainder of the number when its divided by 7
Constraints:
1<=length of n <=10^5
*/
/*                                    ALGORITHM
let us take above Example where number is 12345. 

We reverse the number from end and series from 
the beginning and keep adding multiplication to
the result.
(12345 % 7) = (5*1 + 4*3 + 3*2 + 2*(-1) + 1*(-3)) % 7
            = (5 + 12 + 6 - 2 - 3)%7
            = (18) % 7
            = 4
hence 4 will be the remainder when we divide
the number 12345 by 7.
*/
#include<bits/stdc++.h>

using namespace std;

int remainderWith7(string n)
{
    short a[] = {1,3,2,-1,-3,-2};
    int j=0;
    long long res=0;
    for(int i=n.size()-1;i>=0;i--) {    
       int x=n[i]-48;
       res+=x*a[j];
       j=(j+1)%6; 
    }
    return res%7>=0?res%7:7+res%7;
}

int main()
{
    cout<<remainderWith7("6");
    return 0;
}
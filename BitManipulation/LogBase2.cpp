/*
Find log base 2 of a 32 bit integer:
*/
/*
Logic: We right shift x repeatedly until it becomes 0, meanwhile we keep count on the shift operation. This count value is the log2(x).
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

int main()
{   

    return 0;
}
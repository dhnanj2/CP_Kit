#include<bits/stdc++.h>

using namespace std;

int squares(int a, int b) {
    // O(sqrt(B)) soln:-
    // int c=0;
    // for(int i=1;i*i<=b;i++) {
    //     if(i*i>=a) 
    //         c++;
    // }
    // return c;
    // O(1) soln:-
    return floor(sqrt(b))-ceil(sqrt(a))+1;
}

int main()
{
    cout<<squares(0,10);
    return 0;
}
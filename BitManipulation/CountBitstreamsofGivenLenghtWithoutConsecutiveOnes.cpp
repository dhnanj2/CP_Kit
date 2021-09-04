/*
    Given 'n', count all the bitstreams of length 'n' which doesn't contain consecutive ones.
    for eg:-
    n=2 : 00 01 10 , ans=3
    n=3 : 000 001 010 100 101 , ans=5
*/
/*
solution :- 
actually they forms a fibonacci series 2,3,5,8,....
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> fib;

int count(int n) {
    if(fib.empty()) {
        fib.resize(31,0);
        fib[1]=2;
        fib[2]=3;
        for(int i=3;i<31;i++) {
            fib[i]=fib[i-1]+fib[i-2];
        }
    }
    return fib[n];
}

int main()
{
    
    return 0;
}
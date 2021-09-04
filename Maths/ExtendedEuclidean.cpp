/*
    solution of the equation : ax+by=gcd(a,b)
*/
#include<bits/stdc++.h>

using namespace std;

// solution of the equation : ax+by=gcd(a,b)
int solvexy(int a, int b, int &x, int &y) {
    if(!b) {
        x=1,y=0; // different values of y will produce different solutions of the same eqn which are all correct
        return a;
    }    
    int x1,y1;
    int g=solvexy(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}

int main()
{
    int x,y,a,b;
    cin>>a>>b;
    int gcd = solvexy(a,b,x,y);
    cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<gcd;
    return 0;
}
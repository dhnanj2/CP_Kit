/*
Method 1 (solving LDE)(Works when m and a are coprime) 
The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’, finds their gcd and also find ‘x’ and ‘y’ such that 

ax + by = gcd(a, b)
To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula. Since we know that a and m are relatively prime, we can put value of gcd as 1.

ax + my = 1
If we take modulo m on both sides, we get

ax + my ≅ 1 (mod m)
We can remove the second term on left side as ‘my (mod m)’ would always be 0 for an integer y. 

ax  ≅ 1 (mod m)
So the ‘x’ that we can find using Extended Euclid Algorithm is the multiplicative inverse of ‘a’

Below is the implementation of the above algorithm.
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

// time : O(logP)
// works only if a & p are coprime
// returns 0 if inverse doesn't exist
// return inverse of a under mod p(=1e9+1 by default)
int inverse(int a,int p=1e9+7) {
    int x,y;
    if(solvexy(a,p,x,y)!=1) return 0;
    return (x%p+p)%p;
}

int main()
{
    cout<<inverse(3,11);
    return 0;
}
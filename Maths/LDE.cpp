/*
A Linear Diophantine Equation (in two variables) is an equation of the general form:
ax+by=c
where a, b, c are given integers, and x, y are unknown integers.

In this article, we consider several classical problems on these equations:
finding one solution
finding all solutions
finding the number of solutions and the solutions themselves in a given interval
finding a solution with minimum value of x+y
*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if(!b) {
        x=1,y=0; // different values of y will produce different solutions of the same eqn which are all correct
        return a;
    }    
    int x1,y1;
    int g=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}

void solveforxy(int a, int b, int c,int &x, int &y) {
    if(!b && !a) return;
    int x1,y1;
    int g=gcd(a,b,x1,y1);
    if(c%g!=0) return;
    x=x1*(c/g);
    y=y1*(c/g);
}

/*
From one solution (x0,y0), we can obtain all the solutions of the given equation.
Let g=gcd(a,b) and let x0,y0 be integers which satisfy the following:
a⋅x0+b⋅y0=c
Now, we should see that adding b/g to x0, and, at the same time subtracting a/g from y0 will not break the equality:
a⋅(x0+bg)+b⋅(y0−ag)=a⋅x0+b⋅y0+a⋅bg−b⋅ag=c
Obviously, this process can be repeated again, so all the numbers of the form:
x=x0+k⋅bg
y=y0−k⋅ag
are solutions of the given Diophantine equation.
Moreover, this is the set of all possible solutions of the given Diophantine equation.
*/

int main()
{
    int x,y,a,b,c;
    cin>>a>>b>>c;
    solveforxy(a,b,c,x,y);
    cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<c;
    return 0;
}
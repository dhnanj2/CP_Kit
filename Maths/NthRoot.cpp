/*
As this problem involves a real valued function A^(1/N) we can solve this using Newton’s method, which starts with an initial guess and iteratively shift towards the result. 
We can derive a relation between two consecutive values of iteration using Newton’s method as follows, 

according to newton’s method
x(K+1) = x(K) – f(x) / f’(x)        
here    f(x)  = x^(N) – A
so    f’(x) = N*x^(N - 1)
and     x(K) denoted the value of x at Kth iteration
putting the values and simplifying we get,
x(K + 1) = (1 / N) * ((N - 1) * x(K) + A / x(K) ^ (N - 1))
Using above relation, we can solve the given problem. In below code we iterate over values of x, until difference between two consecutive values of x become lower than desired accuracy.
Below is the implementation of above approach: 
*/
#include<bits/stdc++.h>

using namespace std;

// return A^(1/N)
double nthRoot(int A, int N)
{
    // initially guessing a random number between
    // 0 and 9
    double xPre = rand() % 10;
    //  smaller eps, denotes more accuracy
    double eps = 1e-3;
    // initializing difference between two
    // roots by INT_MAX
    double delX = INT_MAX;
    //  xK denotes current value of x
    double xK;
    //  loop untill we reach desired accuracy
    while (delX > eps)
    {
        //  calculating current value from previous
        // value by newton's method
        xK = ((N - 1.0) * xPre +
              (double)A/pow(xPre, N-1)) / (double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }
    return xK;
}
 

int main()
{

return 0;
}
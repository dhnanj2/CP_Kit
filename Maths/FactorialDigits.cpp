/*
We know,
log(a*b) = log(a) + log(b)

Therefore
log( n! ) = log(1*2*3....... * n) 
          = log(1) + log(2) + ........ +log(n)

Now, observe that the floor value of log base 
10 increased by 1, of any number, gives the
number of digits present in that number.

Hence, output would be : floor(log(n!)) + 1.
*/
#include<bits/stdc++.h>

using namespace std;

int digitsInFactorial(int N)
{
    if(N<0) return 0;
    if(N<=1) return 1;
    double log_fact_n=0;
    for(int i=2;i<=N;i++)    {
        log_fact_n+=log10(i);
    }
    return floor(log_fact_n)+1;
}

int main()
{

return 0;
}
/*                                                   PROBLEM
Given a positive integer value N.
The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.
*/
/*                                                   SOLUTION
    out of 3 divisors, 2 are: 1 and the no. itself.
    thus if a no. i (1<=i<=N) is can be represented as i=a*b and a!=b, it has >3 divisors.
    hence we just need to find the a no. i:(1<=i<=N) and i is a perfect square of a prime no less than i.
    therefore we just need to count the no. of primes with having squares <= N
*/
#include<bits/stdc++.h>

using namespace std;

bool isPrime(int N)
{
    if(N<2) return false;
    for(int i=2;i*i<=N;i++) {
        if(N%i==0) return false;
    }
    return true;
}

int exactly3Divisors(int n)
{
    int cnt=0;
    for(int i=2;i*i<=n;i++) {
        if(isPrime(i)) cnt++;
    }
    return cnt;
}

int main()
{

    return 0;
}
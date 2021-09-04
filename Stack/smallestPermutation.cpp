
//Problem : given a number N, find all numbers upto N whose digits are arranged in smallest possible permutation

#include<bits/stdc++.h>

using namespace std;

int passcode_protected(long long int n) 
{ 
    int result = 0; 
    for (int i = 1; i <= 9; i++) 
    { 
        stack<long long int> s; 
        if (i <= n) 
        { 
            s.push(i); 
            result++; 
        } 
        while (!s.empty()) 
        { 
            long long int tp = s.top(); 
            s.pop(); 

            for (long long int j = tp%10; j <= 9; j++) 
            { 
                long long int x = tp*10 + j; 
                if (x <= n) 
                { 
                    s.push(x); 
                    result++; 
                }
                else
                    break;
            } 
        } 
    } 
    return result; 
} 

int main()
{

    return 0;
}
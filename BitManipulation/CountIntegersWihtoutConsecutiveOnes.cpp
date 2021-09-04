/*
Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

Example 1:
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 

Example 2:
Input: n = 1
Output: 2

Example 3:
Input: n = 2
Output: 3

Constraints:
1 <= n <= 109
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fib;

// count all the bitstreams of length 'n' which doesn't contain consecutive ones.
int count(int n) {
    if(fib.empty()) {
        fib.resize(31,1);
        fib[1]=2;
        fib[2]=3;
        for(int i=3;i<31;i++) {
            fib[i]=fib[i-1]+fib[i-2];
        }
    }
    return fib[n];
}
    int findIntegers(int n) {
        fib.clear();
        int ans=0,i=30,prev_bit=0;
        while(i>=0) {
            if((n&(1<<i))!=0) {
                ans += count(i);
                if(prev_bit) {
                    ans --;
                    break;
                } 
                prev_bit=1;
            }else prev_bit=0;
            i--;
        }
        return ans+1;
    }
};

int main()
{

return 0;
}
/*
Given an integral number N. The task is to find the count of digits present in this number.

Let's say:
N = 2019

Number of digits in N here is 4 and,
the digits are: 2, 0, 1, 9.

Some more Examples:
N = 1567
Number of digits = 4

N = 256
Number of digits = 3

N = 58964
Number of digits = 5
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
                                                SOLUTION 1
Simple Solution: A Simple Solution that comes in mind is:

Check whether the number N is equal to zero.
Increase the count of digits by 1 if N is not zero.
Reduce the number by dividing it by 10.
Repeat the above steps until the number is reduced to zero.

Dry-run of above algorithm: Consider an example, N = 58964. Initialize a variable digitsCount to zero which will store the count of digits. Keep incrementing digitsCount until N is not zero, and reduce it by dividing by 10 at each step.
Iteration 1: N not equals to 0
Increment digitsCount, digitsCount = digitsCount + 1.
digitsCount = 0 + 1 = 1.
N = N/10 = 58964/10 = 5896.

Iteration 2: N not equals to 0
Increment digitsCount, digitsCount = digitsCount + 1.
digitsCount = 1 + 1 = 2.
N = N/10 = 5896/10 = 589.

Iteration 3: N not equals to 0
Increment digitsCount, digitsCount = digitsCount + 1.
digitsCount = 2 + 1 = 3.
N = N/10 = 589/10 = 58.

Iteration 4: N not equals to 0
Increment digitsCount, digitsCount = digitsCount + 1.
digitsCount = 3 + 1 = 4.
N = N/10 = 58/10 = 5.

Iteration 5: N not equals to 0
Increment digitsCount, digitsCount = digitsCount + 1.
digitsCount = 4 + 1 = 5.
N = N/10 = 5/10 = 0.

Iteration 6: N becomes equal to 0.
Terminate any further operation.
Return value of digitsCount.

Therefore, number of digits = 5.

Analysis of above algorithm: You can clearly see that the number of operations performed in the above solution is equal to the count of digits present in the number. So, the time complexity of the solution is O(digitsCount).
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
                                                SOLUTION 2
Better Solution: A better solution is to use mathematics to solve this problem. The number of digits in a number say N can be easily obtained by using the formula:
number of digits in N = log10(N) + 1.

Derivation: Suppose the number of digits in the number N is K.

Therefore, we can say that:
10K-1 <= N < 10K
Applying base-10 logarithm to both sides in the above equation, we get:
K-1 <= log10(N) < K.

or, K - 1 + 1 <= log10(N) + 1 < K + 1
or, K <= log10(N) + 1 < K + 1 
Therefore,
K = floor(log10(N) + 1)

Analysis of above algorithm: Since the above algorithm works in a single operation by using two mathematical operations i.e., finding logarithmic and floor value. Therefore, the time complexity of the solution is O(1).
*/
#include<bits/stdc++.h>

using namespace std;

// time:O(no. of digits), space:O(1);
int len1(int N) {
    if(!N) return 1;
    int cnt=0;
    while(N) {
        cnt++;
        N/=10;
    }
    return cnt;
}

// time:O(1), space:O(1);
int len2(int N) {
    if(!N) return 1;
    return log10(N)+1;
}

int main()
{
    cout<<len1(5)<<" "<<len2(10);
    return 0;
}
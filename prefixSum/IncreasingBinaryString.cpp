/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
Return the minimum number of flips to make s monotone increasing.

Example 1:
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
 
Constraints:
1 <= s.length <= 105
s[i] is either '0' or '1'.
*/
/*
For say a 5 digit string, the answer is either '00000', '00001', '00011', '00111', '01111', or '11111'. Let's try to calculate the cost of switching to that answer. The answer has two halves, a left (zero) half, and a right (one) half.
Evidently, it comes down to a question of knowing, for each candidate half: how many ones are in the left half, and how many zeros are in the right half.
We can use prefix sums. Say P[i+1] = A[0] + A[1] + ... + A[i], where A[i] = 1 if S[i] == '1', else A[i] = 0. We can calculate P in linear time.
Then if we want x zeros followed by N-x ones, there are P[x] ones in the start that must be flipped, plus (N-x) - (P[N] - P[x]) zeros that must be flipped. The last calculation comes from the fact that there are P[N] - P[x] ones in the later segment of length N-x, but we want the number of zeros.
*/
#include<bits/stdc++.h>

using namespace std;

int minFlipsMonoIncr(string s) {
        int n=s.size();
        int ans=n;
        int ones[n+1];
        ones[0]=0;
        for(int i=0;i<n;i++) {
            ones[i+1]=ones[i];
            if(s[i]=='1') ones[i+1]++;
        }
        for(int i=0;i<=n;i++) {
            int no_of_flips=ones[i]+(n-i)-(ones[n]-ones[i]);
            ans=min(ans,no_of_flips);
        }
        return ans;
    }
    
int main()
{

    return 0;
}
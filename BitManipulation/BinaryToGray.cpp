/*
You are given a decimal number N. You need to find the gray code of the number N and convert it into decimal.
To see how it's done, refer here.

Example 1:

Input: N = 7
Output: 4
Explanation: 7 is represented as 111 in 
binary form. The gray code of 111 is 100, 
in the binary form whose decimal equivalent 
is 4.
Example 2:

Input: N = 10
Output: 15
Explanation: 10 is represented as 1010 in 
binary form. The gray code of 1010 is 1111, 
in the binary form whose decimal equivalent 
is 15.
Example 3:

Input: N = 0
Output: 0
Explanation: Zero is represented as zero 
in binary, gray, and decimal.

Your Task: The task is to complete the function greyConverter() which takes n as a parameter and returns it's equivalent gray code.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
0 <= N <= 109
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(1) , space : O(1)
int greyConverter(int n)
{
    bitset<32> bin(n);
    string s=bin.to_string();
    string ans;
    char prev=s[0];
    ans.push_back(s[0]);
    for(int i=1;i<s.size();i++) {
        if(prev!=s[i]) {
           ans.push_back('1') ;
        }else  {
           ans.push_back('0') ;
        }
        prev=s[i];
    }
    bitset<32> grey(ans);
    return grey.to_ulong();
}

int main()
{
    greyConverter(7);
    return 0;
}

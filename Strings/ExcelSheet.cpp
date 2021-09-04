/*
Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Example 1:
Input:
N = 51
Output: AY
Your Task:
Complete the function ExcelColumn() which takes N as input and returns output string.

Expected Time Complexity: O(Log(N))
Expected Auxiliary Space: O(Log(N))

Constraints:
1 ≤ N ≤ 10^7
*/
#include<bits/stdc++.h>

using namespace std;

// time : O()
string ExcelColumn(int N)
{
    vector<char> a;
    for(char i='A';i<='Z';i++) {
        a.push_back(i);
    }
    string ans;
    while(N){
        ans.push_back(a[(--N)%26]);
        N/=26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{

    return 0;
}
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
*/
#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string s) {
    int op=0;
    for(auto i:s) {
        if(i=='(') op++;
        else {
            if(op>0) op--;
            else return false;
        }
    }
    return op==0;
}
    
void helper(int n, vector<string> &a,string s="") {
    if(s.size()>=n) {
        cout<<s<<"  ";
        if(isBalanced(s)) a.push_back(s);
        return; 
    }     
    s.push_back('(');
    helper(n,a,s);
    s.pop_back();
    s.push_back(')');
    helper(n,a,s);
}
    
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helper(2*n,ans);
    return ans;
}

int main()
{

    return 0;
}
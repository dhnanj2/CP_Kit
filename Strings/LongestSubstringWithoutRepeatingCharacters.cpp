/*
Given a string S, find the length of its longest substring that does not have any repeating characters.

Example 1:

Input:
S = geeksforgeeks
Output: 7
Explanation: The longest substring
without repeated characters is "ksforge".
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(|S|) , space : O(1)
// soln assumes that string only contain lowercase alphabets.
// uses sliding window technique
int SubsequenceLength (string s) 
{
    vector<int> vis(26,-1);
    int ans=0,len=0;
    for(int i=0;i<s.size();i++) {
        // if the current char is not yet visited or was visited outside the current window then include it in the window and increase the window size by one 
        // else if the char is already in window exclude its previous presence in the window and include is current presence
        if(vis[s[i]-'a']<0 || vis[s[i]-'a']<i-len) {
            vis[s[i]-'a']=i;
            len++;
        }else {
            len=i-vis[s[i]-'a'];
            vis[s[i]-'a']=i;
        }
        ans=max(ans,len);
    }
    return ans;
}

int main()
{

    return 0;
}
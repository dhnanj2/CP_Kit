/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

Constraints:
1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

int numMatchingSubseq(string s, vector<string>& words) {
    int ans=0;
    vector<int> a[26];
    for(int i=0;i<s.size();i++) {
        a[s[i]-'a'].push_back(i);
    }
    for(auto i:words) {
        int pre=-1;
        bool flg=true;
        for(auto j:i) {
            auto id=upper_bound(a[j-'a'].begin(),a[j-'a'].end(),pre);
            if(id==a[j-'a'].end()) {
                flg=false;
                break;
            }else {
                pre=*id;
            }
        }
        if(flg)ans++;
    }
    return ans;
}

int main()
{

    return 0;
}
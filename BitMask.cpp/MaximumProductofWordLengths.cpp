/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

Example 1:
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

Example 2:
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".

Example 3:
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.

Constraints:
2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.
*/
#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<string>& words) {
    size_t ans=0;
    vector<int> mask(words.size(),0);
    for(int i=0;i<words.size();i++) {
        for(int j=0;j<words[i].size();j++) {
            int k=words[i][j]-'a';
            mask[i] |= (1<<k);
        }
    }
    for(int i=0;i<words.size();i++) {
        for(int j=i+1;j<words.size();j++) {
            if(!(mask[i]&mask[j]==0)) ans = max(ans,words[i].size()*words[j].size());
        }
    }
    return ans;
}

int main()
{

    return 0;
}
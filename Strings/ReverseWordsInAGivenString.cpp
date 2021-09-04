/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
*/

#include<bits/stdc++.h>

using namespace std;

// time : O(|S|) ,space : O(no. of words)
string reverseWords(string S) 
{ 
    vector<pair<int,int>> word;
    for(int i=0;i<S.size();) {
        int j=i;
        while(j<S.size() && S[j]!='.' )j++;
        word.push_back(make_pair(i,j));
        i=j+1;
    }
    
    // for(auto i:word) cout<<i.first<<" "<<i.second<<"\n";
    for(auto i:word) {
        int s=i.first,e=i.second;
        reverse(S.begin()+s,S.begin()+e);
    }
    reverse(S.begin(),S.end());
    return S;
} 

int main()
{
    auto s=reverseWords("i.like.this.program.very.much");
    cout<<s;
    return 0;
}
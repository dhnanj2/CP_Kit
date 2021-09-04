/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"

Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define all(c) (c).begin(), (c).end()

#define sz(x) (int)(x).size()

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

#define pii pair<int,int>

#define ll long long 

#define pb push_back

#define S second

#define F first

const int MOD = 1e9+7;

static const auto __optimize__ = []() {

std::ios::sync_with_stdio(false);

std::cin.tie(nullptr);

std::cout.tie(nullptr);

return 0;

}();

bool comp(string l, string r) {
    if(l.size()!=r.size())
        return l.size()>r.size();
    else
        return l<r;    
}

string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(),comp);   
    for(auto w:d) {
        int j=0;
        // O(s.size())
        for (int i = 0; i < s.size() && j < w.size(); i++)
        if (w[j] == s[i])
            j++;
        // If all characters of w were found in s
        if (j == w.size()) {
            return w;  
        }  
    }
    return "";
}
                            // Time Complexity : O(s.size()*d.size())
int main()
{

    return 0;
}
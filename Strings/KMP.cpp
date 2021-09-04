#include<bits/stdc++.h>

using namespace std;

// time:O(m) , space : O(m)
vector<int> buildLPS(string s) {
    vector<int> lps(s.size(),0);
    int j=0;
    for(int i=1;i<s.size();i++) {
        while(s[i]==s[j]) lps[i++]=++j;
        j=0;
    }
    return lps;
}

// time:O(m+n) , space : O(m)
// XXXXXXXXXX wrong XXXXXX Pls correct before using it
vector<int> KMP(string text, string ptrn) {
    auto lps = buildLPS(ptrn);
    // for(auto i:lps) cout<<i<<" ";
    int j=0;
    vector<int> pos;
    for(int i=0;i<text.size();i++) {
        while(i<text.size() && text[i]==ptrn[j]) {
            i++,j++;
            if(j>=ptrn.size()) {
                pos.push_back(i-ptrn.size());
                j=lps[ptrn.size()-1];
                continue;
            }
        }
        j=lps[max(j-1,0)];
    }
    return pos;
}

// ptrn : aabcdaabcb
//        0100012340  
int main()
{
    string txt = "geeks for geeks";
	string pat = "aabcdaabcb";
    auto ans = buildLPS(pat);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}
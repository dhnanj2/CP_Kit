/*
You are given a string s. You need to find the missing characters in the string to make a panagram.
Note: The output characters will be lowercase and lexicographically sorted.
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(n) , space : O(1);
string missingPanagram(string str){
    set<char> ltrs;
    for(char i='a';i<='z';i++) {
        ltrs.insert(i);
    }
    for(auto i:str) {
        if(isupper(i)) {
            i=tolower(i);
        }
        ltrs.erase(i);
    }
    if(ltrs.empty()) return "-1";
    string ans(ltrs.begin(),ltrs.end());
    return ans;
}

int main()
{

return 0;
}
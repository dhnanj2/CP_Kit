#include<bits/stdc++.h>

using namespace std;

bool isPalindrome (string s) {
    int i=0,j=s.size()-1;
    while(i<j) {
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string,int> m;
    vector<vector<int>> ans;
    int k=1;
    for(auto i:words) {
        m[i]=k++;
    }
    int n=words.size();
    for(int i=0;i<n;i++)  {
        for(int j=0;j<words[i].size();j++) {
            auto w = words[i].substr(j);
            auto s=words[i].substr(0,j);
            reverse(w.begin(),w.end());
            if(isPalindrome(s) && m[w] && m[w]-1!=i) {
                vector<int> t{m[w]-1,i};
                ans.push_back(t);
            }
            w=words[i].substr(0,j);
            s = words[i].substr(j);
            reverse(w.begin(),w.end());
            if(isPalindrome(s) && m[w] && m[w]-1!=i) {
                vector<int> t{i,m[w]-1};
                ans.push_back(t);
            }
        }
        if(words[i].size() && isPalindrome(words[i]) && m[""]) {
            vector<int> t{i,m[""]-1},s{m[""]-1,i};
            // ans.push_back(t);
            ans.push_back(s);
        }
    }        
    return ans;
}

int main()
{

return 0;
}
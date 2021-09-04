#include<bits/stdc++.h>

using namespace std;

// time : O(N*k) , space : O(k)
// where , N=s1.size=s2.size and k=occurance of s1[0] in s2
bool areRotations(string s1,string s2)
{
    if(s2.size()!=s1.size()) return false;
    char c=s1[0];
    vector<int> pos2;
    for(int i=0;i<s2.size();i++) {
        if(s2[i]==c) {
            pos2.push_back(i);
        }
    }
    int n=s1.size();
    for(auto i:pos2) {
        bool flg=true;
        for(int j=0;j<s1.size();j++) {
            if(s1[j]!=s2[(j+i)%n]) {
                flg=false;
                break;
            }
        }
        if(flg) return true;
    }
    return false;
}

int main()
{

    return 0;
}
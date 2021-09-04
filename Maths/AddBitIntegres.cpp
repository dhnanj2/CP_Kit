#include<bits/stdc++.h>

using namespace std;

class BigInteger {
    string s;

    public : 

    BigInteger(string s) : s(s) {}

    friend string operator+(BigInteger ,BigInteger) ;
};

string operator+(BigInteger a,BigInteger b) {
    auto sa=a.s,sb=b.s;
    int i=sa.size()-1,j=sb.size()-1,c=0;
    string ans;
    while(i>=0 && j>=0) {
        int x=sa[i--]-'0',y=sb[j--]-'0';
        int z=x+y+c;
        ans.push_back('0'+z%10);
        c=z/10;
    }
    while(i>=0) {
        int x=sa[i--]-'0';
        int z=x+c;
        ans.push_back('0'+z%10);
        c=z/10;
    }
    while(j>=0) {
        int x=sb[j--]-'0';
        int z=x+c;
        ans.push_back('0'+z%10);
        c=z/10;
    }
    if(c) ans.push_back('0'+c);
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    auto a=BigInteger("1");
    auto b=BigInteger("9");
    cout<<(a+b);
    return 0;
}
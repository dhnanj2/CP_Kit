#include<bits/stdc++.h>

using namespace std;

// time:O(Log(N)*Log(N)) , space:O(1)
string convertToRoman(int n) 
{
    string ans;
    map<int,string> roman{
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
    };
    while(n) {
        auto it = roman.lower_bound(n);
        if(it==roman.end() || it->first > n) it--;
        n -= it->first;
        ans += it->second;
    }
    return ans;
}

// time : O(X), space:O(1), where X->length of the corresponding roman number or X=Log13(N)
string intToRoman(int num) {
 vector<pair<int,string>>m={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
    string ans="";
    for(auto it=m.rbegin();it!=m.rend() && num!=0;it++)
    {
        int freq=num/it->first; // Get the frequecy of symbols required, starting from the largest and going to the least
        num=num%it->first; // Update num for the next iteration so that we can get the frequency of the second highest symbol and so on
        while(freq)
        {
            ans.append(it->second); //append the symbol as many times as frequency and decrease it
            freq-=1;
        }
    }
    return ans; // return answer
}

int main()
{
    
    return 0;
}
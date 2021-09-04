#include<bits/stdc++.h>

using namespace std;

string reverseWord(string &str){
    //Your code here
    int n=str.size();
    int mid = str.size()/2;
    for(int i=0;i<mid;i++) {
        swap(str[i],str[n-i-1]);
    }
    return str;
}

int main()
{
    
    return 0;
}
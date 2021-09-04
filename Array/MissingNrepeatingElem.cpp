/*
Description: Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Our task is to find these two numbers.
Input
[2, 3, 2, 1, 5]
Output
4 2
*/
#include<bits/stdc++.h>

using namespace std;

// time:O(N), space:O(1)
pair<int,int> MissingNrepeatingElem(vector<int> a) {
    pair<int,int> ans=make_pair(0,0);
    int n=a.size();
    for(auto &i:a) {
        while(i>=1 && i<=n && i!=a[i-1]) swap(i,a[i-1]);
    }
    for(int i=0;i<n;i++) {
        if(a[i]!=i+1) ans=make_pair(i+1,a[i]);
    }
    return ans;
}

int main()
{
    auto p=MissingNrepeatingElem({2,1,2,3});
    cout<<p.first<<" "<<p.second;
    return 0;
}
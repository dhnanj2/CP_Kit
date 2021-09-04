/*
Move all negative numbers to beginning and positive to end with constant extra space
Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
*/
#include<bits/stdc++.h>

using namespace std;

// Time : O(N) , space:O(1) 

void partition(vector<int> &a) {
    int i=0 , j=a.size()-1;
    while(i<=j) {
        if(a[i]>=0 && a[j]<0) swap(a[i],a[j]);
        if(a[i]<0) i++;
        if(a[j]>=0) j--;
    }
}

int main()
{
    vector<int> v{0,1,2,1,2,3};
    partition(v);
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}
/*
Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:
Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5
*/
#include<bits/stdc++.h>

using namespace std;

// timr :O(N) , space : O(N)
int maxDistance(int a[], int n)
{
    unordered_map<int,int> rmi; //right most index of an element 
    unordered_map<int,int> lmi; //left most index of an element
    for(int i=0;i<n;i++) {
        if(!rmi[a[i]] || rmi[a[i]]<i) rmi[a[i]]=i+1;
        if(!lmi[a[i]] || lmi[a[i]]>i) lmi[a[i]]=i+1;
    }
    int ans=0;
    for(auto i:rmi) {
        ans=max(ans,i.second-lmi[i.first]);
    }
    return ans;
}

int main()
{

    return 0;
}
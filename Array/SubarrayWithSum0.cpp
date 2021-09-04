/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
*/
/*                                      solution
Step1: Iterate through the array and for every element arr[i], calculate sum of elements form 0 to i (this can simply be done as sum += arr[i]).
Step 2: If the current sum has been seen before, then there is a zero sum array. 
Hashing is used to store the sum values, so that we can quickly store sum and find out whether the current sum is seen before or not.
*/
#include<bits/stdc++.h>

using namespace std;

bool subArrayExists(int a[], int n)
{
    unordered_map<int,bool> vis;
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        if(vis[sum] || !a[i] || !sum)    
            return true;
        vis[sum] = true;
    }
    return false;
}

int main()
{

    return 0;
}
/*
Given an array arr[] of size N where every element is in the range from 0 to n-1.
Rearrange the given array so that arr[i] becomes arr[arr[i]].
*/

#include<bits/stdc++.h>

using namespace std;

// time:O(N), space:O(1)
void arrange(long long a[], int n) {
    //at each index we'll store its initial value and final value as follows:-
    //a[i] = prev + final*n
    // we can access both the initial and final values as follows:-
    // prev=a[i]%n, final=a[i]/n
    for(int i=0;i<n;i++){
        a[i]=a[i]+(a[a[i]]%n)*n;
    }
    for(int i=0;i<n;i++){
        a[i]=a[i]/n;
    }
}

int main()
{

return 0;
}
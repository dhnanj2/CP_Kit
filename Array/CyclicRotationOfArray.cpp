/*
Given an array, rotate the array by one position in clock-wise direction.
Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
*/

#include<bits/stdc++.h>

using namespace std;

void rotate_right(int arr[], int s, int e)
{
    int t=arr[s];
    for(int i=s+1;i<=e;i++) {
        swap(arr[i],t);
    }
    arr[s]=t;
}

void rotate_left(int arr[], int s, int e)
{
    int t=arr[s];
    for(int i=s;i+1<=e;i++) {
        arr[i] = arr[i+1];
    }
    arr[e]=t;
}


int main()
{
    int a[] = {1,2,3,4,5};
    rotate_left(a,0,2);
    for(int i=0;i<5;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
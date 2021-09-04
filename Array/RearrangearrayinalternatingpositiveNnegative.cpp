/*
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every negative number is followed by positive and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. 
If there are more negative numbers, they too appear in the end of the array.

Problem : https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
*/
#include<bits/stdc++.h>

using namespace std;
/*
                                        ALGORITHM
    The above problem can be easily solved if O(n) extra space is allowed. 
    It becomes interesting due to the limitations that O(1) extra space and order of appearances. 
    The idea is to process array from left to right. 
    While processing, find the first out of place element in the remaining unprocessed array. 
    An element is out of place if it is negative and at even index, or it is positive and at odd index. 
    Once we find an out of place element, we find the first element after it with opposite sign. 
    We right rotate the subarray between these two elements (including these two).                                     
*/

// time: O(n), space : O(1)
void rotate_right(int arr[], int s, int e)
{
    int t=arr[s];
    for(int i=s+1;i<=e;i++) {
        swap(arr[i],t);
    }
    arr[s]=t;
}

// time: O(n^2), space : O(1) , BruteForce
void rearrange(int a[], int n) {
    int out_of_place = -1;
    for(int i=0;i<n;i++) {
        if(out_of_place<0) {
            if((i%2==0 && a[i]<0)||(i%2!=0 && a[i]>=0)) {
                out_of_place=i;
            }
            continue;
        }
        if(((a[i]>=0 && a[out_of_place]<0)||(a[i]<0 && a[out_of_place]>=0))) {
            rotate_right(a,out_of_place,i);
            // the new out-of-place entry is now 2 steps
            // ahead
            if (i - out_of_place >= 2)
                out_of_place += 2;
            else
                out_of_place = -1;
        }
    }
}

// time: O(N), space : O(1) , QuickSort Method
// *note : it doesn't preserves order of the array
void rearrange(int a[], int n) {
    // partition the given array(all the +ve elements in the first half array)
    int i=0 , j=n-1;
    while(i<=j) {
        if(a[i]<0 && a[j]>=0) swap(a[i],a[j]);
        if(a[i]>=0) i++;
        if(a[j]<0) j--;
    }
    // now i and j are pointing to first -ve and last +ve element respectively 
    int pos = 1;
    while(pos<i && i<n) {
        swap(a[pos],a[i]);
        pos+=2;
        i++;
    }
}

int main()
{
    int a[] = {0,2,-3,-4,5};
    rearrange(a,5);
    for(int i=0;i<5;i++) 
        cout<<a[i]<<" ";
    
    return 0;
}
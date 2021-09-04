#include<bits/stdc++.h>

using namespace std;

// time:O(N), space:O(1)
// removes duplicates from the sorted array and returns its updated size
// *note : array must sorted
int remove_duplicate(int a[],int n) {
    if (n==0 || n==1) return n; 
    // To store index of next unique element 
    int j = 0; 
    // Doing same as done in Method 1 
    // Just maintaining another updated index i.e. j 
    for (int i=0; i < n-1; i++) 
        if (a[i] != a[i+1]) 
            a[j++] = a[i]; 

    a[j++] = a[n-1]; 
  
    return j; 
}

int main()
{
    int a[] = {2,2,4,5,5};      
    int id = remove_duplicate(a,5);
    for(int i=0;i<id;i++) cout<<a[i]<<" ";
    return 0;
}
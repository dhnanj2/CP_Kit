#include<bits/stdc++.h>

using namespace std;

/*
Traverse the array, Ignore the elements which are greater than n and less than 1.
While traversing check a[i]!=a[a[i]-1] if this condition hold true or not .
If the above condition is true then swap a[i], a[a[i] - 1]  && swap until a[i] != a[a[i] - 1]  condition will fail .
Traverse the array and check whether a[i] != i + 1 then return i + 1.
If all are equal to its index then return n+1.
*/

// time:O(N) ,space:O(1)
int findMissing(int a[], int n) { 
    for(int i=0;i<n;i++) {
        if(a[i]<1 || a[i]>n) continue;
        while (a[i] >= 1 && a[i] <= n && a[i] != a[a[i] - 1]) {
            swap(a[i], a[a[i] - 1]);
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i]!=i+1) return i+1;
    }
    return n+1;
}

int main()
{
    int a[5]={2,3,2,1,5};
    cout<<findMissing(a,5);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int immediateSmaller(int arr[], int n, int x)
{
    // your code here
    int diff=INT_MAX,element=-1;
    for(int i=0;i<n;i++) {
        int t=x-arr[i];
        if(t>0 && t<diff) diff=t,element=arr[i];
    }
    return element;
}

int main()
{
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

// searches for a pair(subset of size=2) with desired sum in the given sorted array using 2pointer in O(N) time
bool pairWithSum(vector<int> &A, int sum, int idx=0) {
    int l=idx , r=A.size()-1;
    while(l<r) {
        if(A[l]+A[r]<sum) l++;
        else if(A[l]+A[r]>sum) r--;
        else return true;
    }
    return false;
}

// Searches for a pair with sum = X-a[i] for each i int the subarray a[i+1....N] 
// Time : O(N^2) , space : O(1)
bool find3Numbers(int a[], int N, int X)
{
    sort(a,a+N);
    vector<int> A(a,a+N);
    int i=0;
    while(i<N && A[i]<=X) {
        if(pairWithSum(A,X-A[i],i+1))
            return true;
        i++;    
    }
    return false;
}

int main()
{

    return 0;
}
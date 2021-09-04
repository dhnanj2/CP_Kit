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

int main()
{

return 0;
}
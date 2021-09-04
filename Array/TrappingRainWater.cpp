#include<bits/stdc++.h>

using namespace std;
/*                                      SOLUTION:
    Traverse through each building and compute and store the water accumulated above the ith building, as:-
        1. for the ith building the water accumulated = min(largest building on its left,largest building on its right)-height of ith building
        2. for computing largest building on left of ith building, we'll use array left[i] and similarly for array right[i] 
    2. return the sum {i=0 to n water[i]}

    complete soln : https://www.youtube.com/watch?v=Uog2Jmyb3iY
*/

// time : O(n) , space:O(n)
int trap(vector<int>& a) {
    if(a.size()<=2)return 0;
    int n=a.size();
    vector<int> left(n,0),right(n,0);
    left[0] = a[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],a[i]);
    }
    right[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],a[i]);
    }
    int  totalWater=0;
    for(int i=0;i<n;i++){
        totalWater += min(left[i],right[i])-a[i];
    }    
    return totalWater;
}

int main()
{
    
    return 0;
}
/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
*/
/*
                                            Kadane's ALGORITHM
Basically its an dynamic programmming solution :-                                            

Time : O(n) & Space : O(n)
dp[i] stores the max sum of the subarray that ends at i
and the ans is max(dp[0],dp[1],dp[2],.....dp[n-1])

Time : O(n) & Space : O(1)
Initialize:

    max_so_far = 0

    max_ending_here = 0

Loop for each element of the array

  (a) max_ending_here = max_ending_here + a[i]

  (b) if(max_so_far < max_ending_here)

            max_so_far = max_ending_here

  (c) if(max_ending_here < 0)

            max_ending_here = 0

return max_so_far
*/
#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(int arr[], int n){
    // Your code here
    int max_so_far = INT_MIN, max_ending_here = 0;
    
    for (int i = 0; i<n ; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    
    return max_so_far;
}

// https://www.youtube.com/watch?v=VMtyGnNcdPw
int maxSubarraySum(int arr[], int n){
    int overall_best=arr[0] , cur_best=arr[0];
    for(int i=1;i<n;i++) {
        cur_best = max(cur_best+arr[i],arr[i]);
        overall_best = max(overall_best,cur_best);
    }
    return overall_best;
}

int main()
{

return 0;
}
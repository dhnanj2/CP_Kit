/*
Given an array of N elements, the task is to minimize the maximum difference of adjacent elements by inserting at most K elements in the array.
Examples: 
Input: arr = [2, 6, 8] K = 1 
Output: 2 
Explanation: 
After insertion of 4 in between 2 and 6, the array becomes [2, 4, 6, 8]. In this case the maximum difference between any adjacent element is 2, which is the minimum that can be.
Input: arr = [3, 12] K = 2 
Output: 3 
Explanation: 
After insertion of 6 and 9 in between 3 and 12, the array becomes [3, 6, 9, 12]. In this case the maximum difference between any adjacent element is 3, which is the minimum that can be. 
*/
/*
Approach: In order to solve this problem, we are using the following Binary Search based approach:

Find the maximum difference between any two adjacent element in the array and store it in a variable, say worst.
Search from best(1 initially) to worst and for every mid value find the number of insertions required.
Whenever the number of insertions is greater than K for a particular value of mid, search between [mid + 1, worst], that is the higher half. Otherwise search between [best, mid-1], that is the lower half to check if the maximum difference can be further minimized with at most K insertions.
The final worst value after termination of the loop gives the answer.
*/

// Time:O(N) , space:O(1)
#include<bits/stdc++.h>

using namespace std;


bool isPossible(int diff[], int n, int target) {
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(diff[i]>=target) {
            cnt += ceil((float)diff[i]/target)-1;
        }
    }
    return cnt<=target;
}

int minimizedMaxDiff(int a[], int n, int k)
{
    int worst=INT_MIN;
    int diff[n-1]={ };
    for(int i=0;i+1<n;i++) {
        diff[i]=abs(a[i]-a[i+1]);
        worst=max(worst,diff[i]);
    }
    int l=1 , r=worst,ans=worst;
    while(l<=r) {
        int mid=(l+r)/2;
        if(isPossible(diff,n-1,mid)) {
            ans = mid;
            r=mid-1;
        }else {
            l=mid+1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}
/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Constraints:
1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/
/*
Algorithm
We can view any given sequence in numsnums array as alternating ascending and descending sequences. By making use of this, and the fact that we can return any peak as the result, we can make use of Binary Search to find the required peak element.

In case of simple Binary Search, we work on a sorted sequence of numbers and try to find out the required number by reducing the search space at every step. In this case, we use a modification of this simple Binary Search to our advantage. We start off by finding the middle element, midmid from the given numsnums array. If this element happens to be lying in a descending sequence of numbers. or a local falling slope(found by comparing nums[i]nums[i] to its right neighbour), it means that the peak will always lie towards the left of this element. Thus, we reduce the search space to the left of midmid(including itself) and perform the same process on left subarray.

If the middle element, midmid lies in an ascending sequence of numbers, or a rising slope(found by comparing nums[i]nums[i] to its right neighbour), it obviously implies that the peak lies towards the right of this element. Thus, we reduce the search space to the right of midmid and perform the same process on the right subarray.

In this way, we keep on reducing the search space till we eventually reach a state where only one element is remaining in the search space. This single element is the peak element.

To see how it works, let's consider the three cases discussed above again.

Case 1. In this case, we firstly find 33 as the middle element. Since it lies on a falling slope, we reduce the search space to [1, 2, 3]. For this subarray, 22 happens to be the middle element, which again lies on a falling slope, reducing the search space to [1, 2]. Now, 11 acts as the middle element and it lies on a falling slope, reducing the search space to [1] only. Thus, 11 is returned as the peak correctly.
*/
#include<bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int>& a) {
    int l=0,r=a.size()-1;
    int ans=0;
    while(l<=r) {
        int m=(l+r)/2;
        if(m+1<a.size() && a[m+1]>a[m]) {
            l=m+1;
        }else if(m>0 && a[m-1]>a[m]) {
            r=m-1;
        }else {
            ans=m;
            break;
        }
    }             
    return ans;
}

int main()
{

    return 0;
}
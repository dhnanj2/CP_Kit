/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018
*/

/*
    Algorithm: 
    1.The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
    2.Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
    3.Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
    4.The base case of recursion is when there is only one element in the given half.
    5.Print the answer
*/

#include<bits/stdc++.h>

using namespace std;

// Time : O(N) , Space:O(N)
void merge(long long a[], long long st , long long end, long long &inversions) {
	// code here
    long long mid = (st+end)/2;
	long long i=st , j=mid+1 , k=st;
	long long temp[end+1] = { };
    
	while(i<=mid && j<=end) {
		if(a[i]<=a[j])
			temp[k++]=a[i++];
        // whenever we take element from right subarray then that element forms a pair with mid-i+1 elements of left subarray
		else {
			temp[k++]=a[j++];
            inversions += (mid-i+1);
        }
	}
	while(i<=mid) {
		temp[k++] = a[i++];
	}
	while(j<=end) {
		temp[k++] = a[j++];
	}
    for(long long i=st;i<=end;i++) {
        a[i] = temp[i];
    }
}

void mergeSort(long long ar[], long long st, long long end, long long &count) {
    if(st>=end)
        return;

    // devide 
    long long mid=(st+end)/2;
    mergeSort(ar,st,mid,count);
    mergeSort(ar,mid+1,end,count);

    // conquer
    merge(ar,st,end,count);
}

long long inversionCount(long long arr[], long long N)
{
    long long count=0;
    mergeSort(arr,0,N-1,count);    
    return count;
}

int main()
{
    
    return 0;
}
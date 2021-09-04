/*
Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.

Example 1:

Input:
N = 5, M = 6 
arr[] = {1,2,3,4,5}
brr[] = {3,4,5,6,7,8}
Output: 4
Explanation: After merging two arrays, 
elements will be as 1 2 3 3 4 4 5 5 6 7 8
So, median is 4.

Example 2:

Input:
N = 2, M = 3 
arr[] = {1,2}
brr[] = {2,3,4}
Output: 2
Explanation: After merging two arrays, 
elements will be as 1 2 2 3 4. So, 
median is 2.

Your Task:
You do not need to read input or print anything. Complete findMedian() function which takes the two arrays and n and m as input parameters and returns their median. If there are total even elements, return floor of average of middle two elements.

Expected Time Complexity : O(log(max(m,n)))
Expected Auxilliary Space : O(1)
*/
/*
reference : https://www.youtube.com/watch?v=yD7wV8SyPrc
*/

#include<bits/stdc++.h>

using namespace std;

// time:O(log(min(n,m))), space:O(1)
int findMedian(int a[], int n, int b[], int m){
    int l=0,r=n;
    int k=(n+m)/2;
    while(l<=r) {
        int mid1=l+(r-l)/2;
        int mid2=k-mid1;
        int l1 = mid1>0? a[mid1-1]:INT_MIN;
        int r1 = mid1<n? a[mid1]:INT_MAX;
        int l2 = mid2>0? b[mid2-1]:INT_MIN;
        int r2 = mid2<m? b[mid2]:INT_MAX;
        if(l1>r2)  {
            r=mid1-1;
        }else if(l2>r1) {
            l=mid1+1;
        }else {
            if((n+m)%2==0) return (max(l1,l2)+min(r1,r2))/2;
            else return min(r1,r2);
        }
    }
    return k;
}

int main()
{

    return 0;
}
/*
Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. 
If there are repetitions, then only one occurrence of element should be printed in union.
Input:
5 3
1 2 3 4 5
1 2 3

Output: 
5

Explanation: 
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.
*/
/*
sort the arrays and use the following algo :-
Union of arrays sorted arrays,  arr1[] and arr2[]

To find union of two sorted arrays, follow the following merge procedure : 
 
1) Use two index variables i and j, initial values i = 0, j = 0 
2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i. 
3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j. 
4) If both are same then print any of them and increment both i and j. 
5) Print remaining elements of the larger array.
*/
#include<bits/stdc++.h>

using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    sort(a,a+n) , sort(b,b+m);
    //'prev' stores the latest element counted/inserted in union thus remove internal duplicacy in individual arrays
    int i=0 , j=0 , ans=0 , prev=-1;
    while (i<n || j<m)
    {
        ans++;
        if(i>=n || j>=m) {
            int cur = i<n ? a[i]:b[j];
            if(prev==cur)
                ans--;
            prev = cur;
            i++ , j++;
            continue;
        }
        if(a[i]<b[j]) {
            if(a[i]==prev)
                ans--;
            prev = a[i];
            i++;
        }
        else if(a[i]>b[j]) {
            if(b[j]==prev)
                ans--;
            prev = b[j];
            j++;
        }
        else {
            if(a[i]==prev)
                ans--;
            prev = a[i];
            i++ , j++;    
        }
    }
    return ans;
}

int main()
{

return 0;
}
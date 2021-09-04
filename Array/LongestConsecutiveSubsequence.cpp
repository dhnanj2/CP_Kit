#include<bits/stdc++.h>

using namespace std;

// Time : O(NlogN) , space : O(1)
/*                                              ALGORITHM
Naive Approach: The idea is to first sort the array and find the longest subarray with consecutive elements. 
After sorting the array and removing the multiple occurrences of elements, run a loop and keep a count and max (both initially zero). 
Run a loop from start to end and if the current element is not equal to the previous (element+1) then set the count to 1 else increase the count.
Update max with a maximum of count and max.
*/

int findLongestConseqSubseq(int a[], int N)
{
    sort(a,a+N);
    int ans=0;
    for(int i=0;i<N;) {
        int j=i+1 , prev=a[i] ,cnt=1;
        while(j<N && (a[j]==prev+1 || a[j]==prev)) {
            cnt = (a[j]==prev+1? cnt+1 : cnt);
            // cout<<a[j]<<" "<<cnt<<"\n";
            prev=a[j++];
        }
        ans = max(ans,cnt);
        i=j;
    }
    return ans;
}

// Time:O(N) ,space:O(N)
/*
  Algorithm: 
    1.Create an empty hash.
    2.Insert all array elements to hash.
    3.Do following for every element arr[i]
    4.Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] - 1 in the hash, if not found, then this is the first element a subsequence.
    5.If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
    6.If the count is more than the previous longest subsequence found, then update this.
*/
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int main()
{
    int a[] = {2,6,1,4,5};
    return 0;
}
/*
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:
Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.
Example 2:

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1
Your Task:
Your task is to complete the function countDistinct() which takes the array A[], the size of the array(N) and the window size(K) as inputs and returns an array containing the count of distinct elements in every contiguous window of size K in the array A[].

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= K <= 105
1 <= A[i] <= 105 , for each valid i
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(N) , space : O(K)
vector <int> countDistinct (int A[], int n, int k)
{
    // stores the freq of an element 
    unordered_map<int,int> m;
    vector<int> ans;
    // construct window
    for(int i=0;i<k;i++) {
        m[A[i]]++;
    }
    ans.push_back(m.size());
    // slide window 
    for(int i=1;i+k<=n;i++) {
        m[A[i-1]]--;
        if(!m[A[i-1]]) m.erase(A[i-1]);
        m[A[i+k-1]]++;
        ans.push_back(m.size());
    }
    return ans;
}

int main()
{   

    return 0;
}
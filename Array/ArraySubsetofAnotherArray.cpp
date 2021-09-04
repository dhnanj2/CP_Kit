/*                              PROBLEM
Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not. 
Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.
Example:
Input:
3
6 4
11 1 13 21 3 7
11 3 7 1
6 3
1 2 3 4 5 6
1 2 4
5 3
10 5 2 23 19
19 5 3

Output:
Yes
Yes
No
*/

#include<bits/stdc++.h>

using namespace std;

//Binary seacrch , Time : O(mlogm + nlogm) ,spce: O(1) 
// *it doesn't consider duplicate elements in array
bool isBSubsetofA(vector<int> A, vector<int> B) {
    if(B.size()>A.size())
        return false;
    sort(A.begin(),A.end());
    for(auto i:B) {
        if(!binary_search(A.begin(),A.end(),i))
            return false;
    }     
    return true;
}

// 2Pointer, Time : O(mlogm + nlogn + (n+m)) ,spce: O(1)
bool isBSubsetofA(vector<int> A, vector<int> B) {
    if(B.size()>A.size())
        return false;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int m=0 , n=0 , match=0;
    while (n<B.size() && m<A.size())
    {
        if(A[m]<B[n]) m++;
        else if(A[m]>B[n]) n++;
        else match++ , m++, n++;
    }
    return match==B.size()? true : false;
}


int main()
{
    int t=0;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        vector<int> A(m,0);
        vector<int> B(n,0);
        for(auto &i:A) 
            cin>>i;
        for(auto &i:B) 
            cin>>i;
        cout<<isBSubsetofA(A,B)<<"\n";
    }
    return 0;
}
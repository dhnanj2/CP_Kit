/*
1. Initialize index of chosen elements as 0. Let this index be 
   'index'
2. Traverse through all bits starting from most significant bit. 
   Let i be the current bit.
......(a) Find the maximum element with i'th bit set.  If there
          is no element with i'th bit set, continue to smaller 
          bit.  
......(b) Let the element with i'th bit set be maxEle and index
          of this element be maxInd. Place maxEle at 'index' and
          (by swapping set[index] and set[maxInd]) 
......(c) Do XOR of maxEle with all numbers having i'th  bit as set.
......(d) Increment index 
3. Return XOR of all elements in set[]. Note that set[] is modified
   in step 2.c.
*/
#include<bits/stdc++.h>

using namespace std;

// Find the maximum element with i'th bit set.
int find(int a[], int N, int start, int bit) {
    int id=-1;
    for (int i = start; i < N ; i++)
    {
        if(a[i]&(1<<bit)) {
            if(id<0 || a[i]>a[id]) id=i;
        }
    }
    return id;
}

int maxSubarrayXOR(int arr[], int N)
{
    int j=0;
    for(int i=31;i>=0;i--) {
       int maxInd=find(arr,N,j,i);
        // cout<<i<<" "<<maxInd<<"\n";
       if(maxInd<0) continue;
       swap(arr[j],arr[maxInd]);
       maxInd=j++;
       for (int k=0; k<N; k++)
       {
           // XOR set[maxInd] those
           // numbers which have the
           // i'th bit set
           if (k != maxInd && (arr[k] & (1 << i)) != 0)
               arr[k] = arr[k] ^ arr[maxInd];
       }
    }
    int ans=0;
    for (int k=0; k<N; k++)
    {
        ans^=arr[k];
    }
    return ans;
}

int main()
{
    int a[]={2,4,5};
    cout<<maxSubarrayXOR(a,3);
    return 0;
}
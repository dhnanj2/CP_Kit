#include<bits/stdc++.h>

using namespace std;

// Time : O(N) , Space:O(N)
void merge(int a[], int st , int end) {
	int mid = (st+end)/2;
	int i=st , j=mid+1 , k=st;
	int temp[end+1] = { };
    
	while(i<=mid && j<=end) {
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid) {
		temp[k++] = a[i++];
	}
	while(j<=end) {
		temp[k++] = a[j++];
	}
    for(int i=st;i<=end;i++) {
        a[i] = temp[i];
    }
}

// Time:O(NlogN)->worst case, 
// Time:O(NlogN)->Best case, 
//  Space:O(N)
// stable sorting atlgorithm (order of values is presereved in case of different values with same keys)
void mergeSort(int ar[], int st, int end) {
    if(st>=end)
        return;

    // devide 
    int mid=(st+end)/2;
    mergeSort(ar,st,mid);
    mergeSort(ar,mid+1,end);

    // conquer
    merge(ar,st,end);
}

int main()
{
    int ar[] = {2,3,2,3};
    mergeSort(ar,0,3);
    for(int i=0;i<4;i++) {
        cout<<ar[i]<<" ";
    }
    return 0;
}
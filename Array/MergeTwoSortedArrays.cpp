// problem : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

#include<bits/stdc++.h>

using namespace std;

// time: O(max(n,m)+nlogn+mlogm) , space : O(1)
void merge(int arr1[], int arr2[], int n, int m) {
	// code here
	int i=n-1 , j=0; 
	while(i>=0 && j<m) {
	    if(arr1[i]>arr2[j]) {
	        swap(arr1[i],arr2[j]);
	    }
	    i-- , j++;
	}
	sort(arr1,arr1+n);
	sort(arr2,arr2+m);
}

// time: O(n+m) , space : O(n+m)
void merge(int arr1[], int arr2[], int n, int m) {
	// code here
	int i=0 , j=0 , k=0;
	int temp[n+m] = { };
	while(i<n && j<m) {
		if(arr1[i]<arr2[j])
			temp[k++]=arr1[i++];
		else
			temp[k++]=arr2[j++];
	}
	while(i<n) {
		temp[k++] = arr1[i++];
	}
	while(j<m) {
		temp[k++] = arr2[j++];
	}
}

int main()
{	
	return 0;
}
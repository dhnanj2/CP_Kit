#include<bits/stdc++.h>

using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m) {
        if(arr1[i]<arr2[j]) {
            ans.push_back(arr1[i]);
            int k=i;
            while(i<n && arr1[k]==arr1[i]) i++;
        }
        else if(arr1[i]>arr2[j]) {
            ans.push_back(arr2[j]);
            int k=j;
            while(j<m && arr2[k]==arr2[j]) j++;
        }
        else {
            ans.push_back(arr1[i]);
            int k=i;
            while(i<n && arr1[k]==arr1[i]) i++;
            k=j;
            while(j<m && arr2[k]==arr2[j]) j++;
        }
    }
    while(i<n) {
        ans.push_back(arr1[i]);
        int k=i;
        while(i<n && arr1[k]==arr1[i]) i++;
    }
    while(j<m) {
        ans.push_back(arr2[j]);
        int k=j;
        while(j<m && arr2[k]==arr2[j]) j++;
    }
    return ans;
}

int main()
{
    int a[]={1,2,4,4,5};
    int b[]={1,2,3,3};
    auto v=findUnion(a,b,5,4);
    for(auto i:v) cout<<i<<" ";
    return 0;
}
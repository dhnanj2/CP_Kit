#include<bits/stdc++.h>

using namespace std;

// Time:O(N^2)->worst case, 
// Time:O(N^2)->Best case, 
// space:O(N)
void SelectionSort1(vector<int> &a) {
    vector<int> temp;
    while(temp.size()<a.size()) {
        // select min from the given array
        int min_idx=-1;
        for(auto i=0;i<a.size();i++) {
            min_idx = (min_idx<0 || a[i]<a[min_idx])? i : min_idx;
        }
        temp.push_back(a[min_idx]);
        a[min_idx]=INT_MAX;
    }
    for(auto i=0;i<a.size();i++) {
        a[i]=temp[i];
    }
}

// Time:O(N^2)->worst case, 
// Time:O(N^2)->Best case, 
//  space:O(1)
void SelectionSort(int a[], int size) {
    int k=0;                
    while(k<size) {
        // select min from the subarray [k+1,k+2....n]
        int min_idx=k;
        for(auto i=k+1;i<size;i++) {
            min_idx = (min_idx<0 || a[i]<a[min_idx])? i : min_idx;
        }
        // swap it with a[k] and increament k
        swap(a[k++],a[min_idx]);
    }
    cout<<"array sorted successfully\n";
}

int main()
{
    vector<int> a{2,0,-1,3,-3,2};
    SelectionSort2(a);
    for(auto i:a)
        cout<<i<<" ";
    return 0;
}
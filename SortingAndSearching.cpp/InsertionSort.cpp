#include<bits/stdc++.h>

using namespace std;

// Time:O(N^2)->worst case, 
// Time:O(N)->Best case, 
// space:O(1)
void InsertionSort(vector<int> &a) {
    for(int i=1;i<a.size();i++) {
        int val = a[i];
        int hole=i;
        while (hole>0 && a[hole-1]>val)
        {
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole]=val;                                
    }
}

int main()
{
    vector<int> a{2,0,-1,3,-3,2};
    InsertionSort(a);
    for(auto i:a)
        cout<<i<<" ";
    return 0;
}
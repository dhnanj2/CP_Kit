#include<bits/stdc++.h>

using namespace std;

// Time:O(N^2)->worst case, 
// Time:O(N)->Best case, 
//  space: O(1)
void BubbleSort(vector<int> &a) {
    int last=a.size()-1;
    while (last>0)
    {
        for(int i=0;i+1<=last;i++) {
            if(a[i+1]<a[i]) swap(a[i+1],a[i]);
        }
        last--;
    }
}

int main()
{
    vector<int> a{2,0,-1,3,-3,2};
    BubbleSort(a);
    for(auto i:a)
        cout<<i<<" ";
    return 0;
}
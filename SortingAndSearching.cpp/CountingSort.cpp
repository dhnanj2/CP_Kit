#include<bits/stdc++.h>

using namespace std;

// Time:O(N+K), space:O(N+K) where K=range of array elements
// non-comparison based sorting
void countSort(vector<int> &a) {
    map<int,int> count;
    for(auto i:a) {
        count[i]++;
    }
    int j=0;
    for(auto &i:count) {
        while(i.second--) {
            a[j++]=i.first;
        }
    }
}

int main()
{
    vector<int> a{5,-5,0,1,3,2,-1};
    countSort(a);
    for(auto i:a) cout<<i<<" ";
    return 0;
}
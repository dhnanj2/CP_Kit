#include<bits/stdc++.h>

using namespace std;

// time:O(N) , space:O(N)
void threeWayPartition(vector<int>& array,int a, int b)
{
    vector<int> x,y,z;    
    for(auto i:array) {
        if(i<a) x.push_back(i);
        else if(i>b) z.push_back(i);
        else y.push_back(i);
    }
    int i=0;
    while(i<x.size()) {
        array[i]=x[i];
        i++;
    }
    int j=0;
    while(j<y.size()) {
        array[i++]=y[j++];
    }
    int k=0;
    while(i<z.size()) {
        array[i++]=z[k++];
    }
}

// time:O(NlogN) , space:O(1)
void threeWayPartition(vector<int>& array,int a, int b)
{
    // since b>=a therefore just sorting the given array wil work
    sort(array.begin(),array.end());    
}

// time:O(N) , space:O(1)
void threeWayPartition(vector<int>& array,int a, int b)
{
    // partitioning around a 
    int r=array.size()-1;
    int pidx=0;
    for(int i=0;i+1<=r;i++) {
        if(array[i]<a) {
            swap(array[i],array[pidx]);
            pidx++;
        }
    }
    swap(array[pidx],array[r]);
    pidx=0;
    // partitioning around b 
    for(int i=0;i+1<array.size();i++) {
        if(array[i]<=b) {
            swap(array[i],array[pidx]);
            pidx++;
        }
    }
    swap(array[pidx],array[r]);
}
    

int main()
{   

    return 0;
}
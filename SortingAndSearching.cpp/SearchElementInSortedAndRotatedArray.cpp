#include<bits/stdc++.h>

using namespace std;

// Time:O(N), space
int Search(vector<int> vec, int K) {
    // search for the point about which the array is rotated
    int n=vec.size();
    int l=0,r=n-1,id=n-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(mid<r && vec[mid]>vec[mid+1]) {
            id=mid;
            break;
        }
        else if(mid>l && vec[mid]<vec[mid-1]) {
            id=mid-1;
            break;
        }
        else if(vec[l]>=vec[mid]) {
            r=mid-1;
        }
        else l=mid+1;
    }
    // now search for the element in subarray[0....id]
    int l=0,r=id;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(vec[mid]==K) return mid;
        else if(vec[mid]<K) l=mid+1;
        else r=mid-1;
    }
    // now search for the element in subarray[id....n]
    l=id , r=vec.size()-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(vec[mid]==K) return mid;
        else if(vec[mid]<K) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main()
{

    return 0;
}













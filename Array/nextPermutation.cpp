// solution : https://leetcode.com/problems/next-permutation/solution/

#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int i=nums.size()-1;
    // search for the first decreasing element from the right 
    while(i>0 && nums[i-1]>=nums[i]) i--;
    // nums[i-1] is the desired element 
    // now swap it with the element just greater than it and lying to right of it
    if(i-1>=0) {
        int j=nums.size()-1;
        while(j>i-1 && nums[j]<=nums[i-1]) j--;
        swap(nums[j],nums[i-1]);
    }
    // reverse the subarray lying to the right of i-1;
    int n=nums.size()-1;
    int mid=(i+n)/2;
    for(int k=i;k<=mid;k++) {
        swap(nums[k],nums[n-k+i]);
    }
}

int main()
{
    vector<int> v{1,2,3,4,5,6,7,7,6};
    nextPermutation(v);
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}
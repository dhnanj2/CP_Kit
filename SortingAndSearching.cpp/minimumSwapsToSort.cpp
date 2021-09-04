#include<bits/stdc++.h>

using namespace std;

// Time:O(nlogn) , space:O(2*N)
int minSwaps(vector<int>&nums){
    auto temp=nums;
    sort(temp.begin(),temp.end());
    unordered_map<int,int> pos;
    int cnt=0;
    for(int i=0;i<nums.size();i++) {
        pos[temp[i]]=i;
    }
    for(int i=0;i<nums.size();i++) {
        while(nums[i]!=temp[i]) {
            cnt++;
            swap(nums[i],nums[pos[nums[i]]]);
        }
    }
    return cnt;
}

int main()
{

return 0;
}
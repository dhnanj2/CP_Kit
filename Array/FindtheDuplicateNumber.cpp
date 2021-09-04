/* problem : Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
   There is only one repeated number in nums, return this repeated number.
*/

#include<bits/stdc++.h>

using namespace std;

//              time : O(NLogN+N) , space : O(1)
int findDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=0;i+1<nums.size();i++)  {
        if(nums[i]==nums[i+1])
            return nums[i];
    }         
    return 0;
}

//              time : O(N) , space: O(N)
int findDuplicate(vector<int>& nums) {
    unordered_map<int,bool> vis;
    for(int i=0;i<nums.size();i++)  {
        if(vis[nums[i]])
            return nums[i];
        vis[nums[i]]=true;    
    }         
    return 0;
}

//              Floyd's Algo solution 
//              time : O(N) , space: O(1)
int findDuplicate(vector<int>& nums) {
    int tortoise = nums[0] , hare = nums[nums[0]];
    // phase 1
    while(tortoise!=hare) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }
    // phase 2
    tortoise = nums[0];
    while(tortoise!=hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}


int main()
{   
    
    return 0;
}
// PROBLEM : https://leetcode.com/problems/running-sum-of-1d-array/

#include<bits/stdc++.h>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int prev_sum=0; 
    vector<int> r_sum;
    for(auto i:nums) {
        prev_sum += i;
        r_sum.push_back(prev_sum);
    }
    return r_sum;
}

int main()
{

    return 0;
}
/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
                    // https://www.youtube.com/watch?v=PqEiJDdt3S4
public:
    int triangleNumber(vector<int>& a) {
        int ans=0;
        sort(a.begin(),a.end());
        for(int i=a.size()-1;i>0;i--) {
            int l=0,r=i-1;
            while(l<r) {
                int sum=a[l]+a[r];
                if(sum<=a[i]) l++;
                else {
                    ans += (r-l);
                    r--;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
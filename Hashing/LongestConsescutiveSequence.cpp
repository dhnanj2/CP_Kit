/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
/*
We need to find the longest consecutive sequence in linear time. We can do this if we insert all the elements of nums into a hashset. Once we have inserted all the elements, we can just iterate over the hashset to find longest consecutive sequence involving the current element(let's call it num) under iteration. This can simply be done by iterating over elements that are consecutive to num till we keep finding them in the set. Each time we will also delete those elements from set to ensure we only visit them once.
*/
#include<bits/stdc++.h>

using namespace std;

// Time  : O(N) , space : O(N)
int longestConsecutive(vector<int>& nums) {
	unordered_set<int> s(begin(nums), end(nums)); // inserting all elements into hashset
	int longest = 0;
	for(auto& num : s) {
		int cur_longest = 1;
		// find consecutive elements in the backward and forward direction from num
		for(int j = 1; s.count(num - j); j++) s.erase(num - j), cur_longest++;
		for(int j = 1; s.count(num + j); j++) s.erase(num + j), cur_longest++;
		longest = max(longest, cur_longest);  // update longest to hold longest consecutive sequence till now
	}
	return longest;
}

int main()
{

    return 0;
}
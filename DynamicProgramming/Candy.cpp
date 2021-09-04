/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
    int n=ratings.size();
    vector<int> dp(n,0);   //Initialize dp with 0
    int ans=0;
    dp[0]=1;
    for(int i=0;i+1<n;i++)
    {
          if(ratings[i]<ratings[i+1]) //update the greater one with previous +1
              dp[i+1]=dp[i]+1;
          else
              dp[i+1]=1;// Else update with minimum candies
    }
    for(int i=n-1;i>0;i--) // iterate from the end and do the same
      {
        if(ratings[i-1]>ratings[i])
            dp[i-1]=dp[i]+1;
       }
	   
     for(int i=0;i<n;i++)
         ans=ans+dp[i];  // add all the candies
    return ans;
    }
};

int main()
{

return 0;
}
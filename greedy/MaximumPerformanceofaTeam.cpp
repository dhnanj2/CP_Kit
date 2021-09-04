/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

Example 1:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

Example 2:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

Example 3:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72

Constraints:
1 <= <= k <= n <= 105
speed.length == n
efficiency.length == n
1 <= speed[i] <= 105
1 <= efficiency[i] <= 108
*/
/*
To recap, we will build a greedy algorithm that utilizes the priority queue data structure. Here are the steps in detail.
    *First of all, let's sort the candidates by efficiency in descending order.
    *Then, we will iterate through the sorted candidates.
    *At each iteration, our goal is to construct a team with at most k members, while treating the current candidate as the one with the lowest efficiency on the team.
    *We use a priority queue to store the speeds for the rest k-1 team members. The priority queue is maintained as a sliding window along with our iteration. For example, we pop out the member with the lowest speed when we exceed the predefined capacity of the queue, which is k-1.
*/
#include<bits/stdc++.h>

using namespace std;

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    int m=1e9+7;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++) {
        a.emplace_back(efficiency[i],speed[i]);
    }      
    sort(a.rbegin(),a.rend());
    priority_queue<int,vector<int>,greater<int>> q;
    long sum=0,ans=0;
    for(auto i:a) {
        q.emplace(i.second);
        sum+=i.second;
        if(q.size()>k) {
            sum-=q.top();
            q.pop();
        }
        ans=max(sum*i.first,ans);
    }
    return ans%m;
}

int main()
{

    return 0;
}
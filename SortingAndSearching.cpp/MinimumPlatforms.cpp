/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms,

Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (between 00 to 59).

Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 1000
1 <= A[i] < D[i] <= 2359
*/
/*
Approach: The idea is to consider all events in sorted order. Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed.
Algorithm:
Sort the arrival and departure time of trains.
Create two pointers i=0, and j=0 and a variable to store ans and current count plat
Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
if the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat++ and increment j
Update the ans, i.e ans = max(ans, plat).
*/

#include<bits/stdc++.h>

using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=0,j=0,ans=1,plat=0;
    while(i<n && j<n) {
        if(arr[i]<=dep[j]) i++ , plat++;
        else j++,plat--;
        ans=max(ans,plat);
    }
    return ans;
}

int main()
{
    return 0;
}
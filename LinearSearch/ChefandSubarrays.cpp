//  PROBLEM : https://www.codechef.com/problems/CHEFARRB
/*
SOLUTION
For each position i we will find the smallest j ≥ i such that the OR-sum of A[i…j] larger than or equal to K then we would know that there is N - j + 1 valid sub-array starting at i. Notice that with i fixed OR-sum of A[i…j] increses when j increases (OR-sum increases when we add more numbers). With that we can use binary search with each i to find j If we can calculate OR-sum of A[i…j] efficiently (one way to calculate OR-sum of any A[i…j] is building the segment tree).

The mentioned solution seems to be overkill with this easy problem not to say that it doesn’t give the best run time. We can avoid binary search and use the two pointer technique where one pointer is the position of i and the other one is j. With each i we try to increase j until we got the OR-sum of A[i…j] larger than or equal to K. The OR-sum between i and j can be maintained by keeping the number of bit 1 at each position among all numbers in the sub-array A[i…j]. Basically we maintain an array cnt[0…31] where cnt[i] is the the numbers of numbers in A[i…j] that hava 1 at the ith bit.

All we do is increase i or j, update the cnt[] array and calculate the OR-sum. Update the cnt[] or calculate OR-sum from cnt[] both take O(32) (which is corresponding to the number of bits the max value of A[i]). So the total complexity would be O(N×log(max A[i])).
*/

#include<bits/stdc++.h>

using namespace std;

static const auto __optimize__ = []() {

std::ios::sync_with_stdio(false);

std::cin.tie(nullptr);

std::cout.tie(nullptr);

return 0;

}();


int main()
{
    int t=0;
    cin>>t;
    while (t--)
    {
        int n=0,k=0,cnt=0;
        cin>>n>>k;
        vector<int> a(n,0)   ;
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(auto i=0;i<a.size();i++) {
            int bit_or = a[i];
            int j=i+1;
            while(bit_or<k && j<a.size()) {
                bit_or |= a[j++];
            }
            if(bit_or>=k) {
                int len = n-j+1;                  // A[j...n-1] is the array with all the good subarrays;
                cnt += len*(len+1)/2;             //no. of subarrays of an array with length N = (N)(N+1)/2
            }
        }
        cout<<cnt<<"\n";
    }        
    return 0;
}
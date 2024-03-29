/*
You are given an unordered array consisting of consecutive integers E[1, 2, 3, ..., n] without any duplicates. 
You are allowed to swap any two elements.You need to find the minimum number of swaps required to sort the array in ascending order.

For example, given the array  we perform the following steps:

i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]
It took 5 swaps to sort the array.
*/
#include<bits/stdc++.h>

using namespace std;

int minimumSwaps(vector<int> arr) {
    int cnt=0;
    for (size_t i = 0; i < arr.size() ; i++)
    {
        int sp = arr[i]-1;                      // the sorted pos 
        if(sp!=i) {
            cnt++;
            swap(arr[i],arr[sp]);
            i--;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}
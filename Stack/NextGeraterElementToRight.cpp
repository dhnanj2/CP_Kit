/*
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider next greater element as -1. 
Examples: 
For an array, the rightmost element always has the next greater element as -1.
For an array which is sorted in decreasing order, all elements have next greater element as -1.
For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.  
Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
*/
/*
Algorithm:
    1. create a stack and push a[n-1] in it and push -1 to the ans. 
    2. traverse from right to left {from n-2 to 0} 
    3. at each iteration pop all the elments which are smaller than a[i] from stack
    4. if stack becomes empty after above operation then push -1 to ans otherwise push stk.top()
    5. push a[i] to stk and continue iteration
    6. at the end just reverse the ans-vector.
*/
/*
    *Similarly next greater element to the left can be found by just traversing from left to right.
    *Similarly next smaller element to the left/right can be found by just popping all the elements greater than a[i] from stk.
*/

#include<bits/stdc++.h>

using namespace std;

// time : O(N), space:O(N)
vector<long long> NGR(vector<long long> a, int n){
    vector<long long> ans(1,-1);
    stack<long long>  stk;
    stk.push(a[n-1]);
    for(int i=n-2;i>=0;i--)  {
        while(!stk.empty() && stk.top()<=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// time : O(N), space:O(N)
vector<long long> NGL(vector<long long> a, int n){              // next greater element to left
    vector<long long> ans(1,-1);
    stack<long long>  stk;
    stk.push(a[0]);
    for(int i=1;i<n;i++)  {
        while(!stk.empty() && stk.top()<=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    return ans;
}

// time : O(N), space:O(N)
vector<long long> NSL(vector<long long> a, int n){              // next smaller element to left
    vector<long long> ans(1,-1);
    stack<long long>  stk;
    stk.push(a[0]);
    for(int i=1;i<n;i++)  {
        while(!stk.empty() && stk.top()>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    return ans;
}

// time : O(N), space:O(N)
vector<long long> NSR(vector<long long> a, int n){              // next smaller element to right
    vector<long long> ans(1,-1);
    stack<long long>  stk;
    stk.push(a[n-1]);
    for(int i=n-2;i>=0;i--)  {
        while(!stk.empty() && stk.top()>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;   
}

int main()
{

    return 0;
}
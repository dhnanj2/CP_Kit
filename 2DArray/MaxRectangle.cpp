/*
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.
*/
/*
ALGORITHM:
    1. tranverse row-wise and for each row update the height of column of 1's above it.
    2. for each updated row determine the max area formed by these columns/histograms
    3. return the max area
*/

#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

// time : O(N), space:O(N)
vector<int> NSL(vector<int> a, int n){              // next smaller element to left
    vector<int> ans(1,-1);
    stack<int>  stk;
    stk.push(0);
    for(int i=1;i<n;i++)  {
        while(!stk.empty() && a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(i);
    }
    return ans;
}

// time : O(N), space:O(N)
vector<int> NSR(vector<int> a, int n){              // next smaller element to right
    vector<int> ans(1,n);
    stack<int>  stk;
    stk.push(n-1);
    for(int i=n-2;i>=0;i--)  {
        while(!stk.empty() && a[stk.top()]>=a[i]) stk.pop();
        if(stk.empty()) ans.push_back(n);
        else ans.push_back(stk.top());
        stk.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;   
}

// time : O(N), space:O(N)
int getMaxArea(int arr[], int n) {
    vector<int> a(arr,arr+n);
    auto nsr = NSR(a,n);    
    auto nsl = NSL(a,n);
    int ans=1;
    for(int i=0;i<n;i++) {
        auto area = (nsr[i]-nsl[i]-1)*a[i];
        ans = max(ans,area);
    }
    return ans;
}

// time : O(N), space : O(N)
int maxArea(int M[MAX][MAX], int n, int m) {
    int ans=0;
    for(int i=0;i<n;i++) {
        if(i>0) {
            for(int j=0;j<m;j++) {
                M[i][j] += M[i-1][j];    
            }    
        }
        ans = max(ans,getMaxArea(M[i],m));
    }
    return ans;
}

int main()
{

    return 0;
}
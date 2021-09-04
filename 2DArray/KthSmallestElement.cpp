// https://www.youtube.com/watch?v=G5wLN4UweAM
#include<bits/stdc++.h>

using namespace std;

int count(vector<vector<int>>& a,int val) {
    int n=a.size();
    int i=n-1,j=0;
    int cnt=0;
    while(i>=0 && j<n) {
        int x=a[i][j];
        if(x>val) i--;
        else {
            cnt += (i+1);
            j++;
        }
    }
    return cnt;
}

// time : O(2nlog(a[n-1][n-1])) , space : O(1)
int kthSmallest(vector<vector<int>>& a, int k) {
    int n=a.size();
    int lo=a[0][0];
    int hi=a[n-1][n-1];
    int ans=hi;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(count(a,mid)>=k) {
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    return ans;
}

int main()
{

    return 0;
}
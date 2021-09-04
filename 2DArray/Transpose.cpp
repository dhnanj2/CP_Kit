#include<bits/stdc++.h>

using namespace std;

// time : O(N^2), space:O(1)
// transpose of a square matrix
void transpose_sq(vector<vector<int>> &A) {
    int m=A.size();
    assert(m>0);
    int n=A[0].size();
    assert(n==m);
    for(int i=0;i<m;i++)  {
        for(int j=0;j<i;j++)  {
            swap(A[i][j],A[j][i]);
        }
    }
}

// time : O(MxN), space:O(MxN)
// transpose of a matrix
void transpose(vector<vector<int>> &A) {
    int m=A.size();
    assert(m>0);
    int n=A[0].size();
    vector<vector<int>> B(n,vector<int> (m,0));
    for(int i=0;i<m;i++)  {
        for(int j=0;j<n;j++)  {
            B[j][i]=A[i][j];
        }
    }
    A=B;
}

int main()
{
    vector<vector<int>> A{{0,2,4},
                          {1,3,5},
                          {2,4,6}};
    transpose(A);
    for(auto i:A) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }                            
    return 0;
}
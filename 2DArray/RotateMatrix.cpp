#include<bits/stdc++.h>

using namespace std;

// reference : https://www.youtube.com/watch?v=SoxrXQbhCPI

// time : O(N^2), space:O(1)
// rotate a square matrix by 90* in clockwise direction
void RotateClockwise(vector<vector<int>> &A) {
    int m=A.size();
    assert(m>0);
    int n=A[0].size();
    assert(n==m);
    // first take transpose of matrix
    for(int i=0;i<m;i++)  {
        for(int j=0;j<i;j++)  {
            swap(A[i][j],A[j][i]);
        }
    }
    // reverse each row of the matrix
    for(int i=0;i<m;i++)  {
        reverse(A[i].begin(),A[i].end());
    }
}

// time : O(N^2), space:O(1)
// rotate a square matrix by 90* in counter clockwise direction
void RotateAntiClockwise(vector<vector<int>> &A) {
    int m=A.size();
    assert(m>0);
    int n=A[0].size();
    assert(n==m);
    // first take transpose of matrix
    for(int i=0;i<m;i++)  {
        for(int j=0;j<i;j++)  {
            swap(A[i][j],A[j][i]);
        }
    }
    // reverse each column of the matrix
    for(int i=0;i<m;i++)  {
        for(int j=0;j<m/2;j++) {
            swap(A[j][i],A[m-j-1][i]);
        }
    }
}

int main()
{
    vector<vector<int>> A{{0,2,4},
                          {1,3,5},
                          {2,4,6}};
    RotateAntiClockwise(A);
    for(auto i:A) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }                            
    return 0;
}
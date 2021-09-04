#include<bits/stdc++.h>

using namespace std;

// time : O(MXN) , space : O(1)
void spiralTraversal(vector<vector<int>> &A) {
    int m=A.size();
    assert(m>0);
    int n=A[0].size();
    int r=0,c=0;
    int top=0,bottom=m-1,left=0,right=n-1;
    short dir=0; 
    while(top<=bottom && left<=right) {
        switch (dir)
        {
            case 0:
                {
                    for(int i=left;i<=right;i++) {
                        cout<<A[top][i]<<" ";
                    }
                    top++;
                }
            break;
            case 1:
                {
                    for(int i=top;i<=bottom;i++) {
                        cout<<A[i][right]<<" ";
                    }
                    right--;
                }
            break;
            case 2:
                {
                    for(int i=right;i>=left;i--) {
                        cout<<A[bottom][i]<<" ";
                    }
                    bottom--;
                }
            break;
            default:
                {
                    for(int i=bottom;i>=top;i--) {
                        cout<<A[i][left]<<" ";
                    }
                    left++;
                }
            break;
        }
        dir=(dir+1)%4;
    }
}

int main()
{
    vector<vector<int>> A{{1,2,3},
                          {8,9,4},
                          {7,6,5}};
    spiralTraversal(A);                      
    return 0;
}
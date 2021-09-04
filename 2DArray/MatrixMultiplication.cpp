#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
{
    int n1=A.size() , m1 = A[0].size() , n2=B.size(), m2=B[0].size();
    vector<vector<int>> C;
    if(m1!=n2) return C;
    C.resize(n1,vector<int> (m2,0));
    for(int i=0;i<n1;i++) {
        for(int j=0;j<m2;j++) {
            int prod=0;
            for(int k=0;k<m1;k++) {
                prod+=A[i][k]*B[k][j];
            }
            C[i][j]=prod;
        }
    }
    return C;
}


int main()
{

    return 0;
}
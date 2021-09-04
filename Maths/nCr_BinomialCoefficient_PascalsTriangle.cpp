#include<bits/stdc++.h>

using namespace std;

// builds first 'N' rows of pascal triangle in O(N^2) time 
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> C(numRows);
    C[0].resize(1,1);
    for(int i=1;i<numRows;i++) {
        C[i].resize(i+1,0);
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    return C;
}

int main()
{
    auto nCr = generate(5);
    cout<<nCr[5][0];        // = 5C2
    return 0;
}
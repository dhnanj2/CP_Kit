// tutorial : https://www.youtube.com/watch?v=EEb6JP3NXBI
/*
Effective computation of Fibonacci numbers
Problem: Compute n-th Fibonacci number Fn in O(logN) time.

Solution: For more details, see the Fibonacci Number article. 
We will only go through an overview of the algorithm. 
To compute the next Fibonacci number, only the two previous ones are needed, as Fn=Fn−1+Fn−2. 
We can build a 2×2 matrix that describes this transformation: the transition from Fi and Fi+1 to Fi+1 and Fi+2. 
For example, applying this transformation to the pair F0 and F1 would change it into F1 and F2. 
Therefore, we can raise this transformation matrix to the n-th power to find Fn in time complexity O(logn)

using above method we get :-

|f(n)  | = |1 1|^n-1 * |f(n-1)|  
|f(n-1)|   |1 0|       |f(n-2)| 

*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<long long>> operator* ( const vector<vector<long long> >& A, const vector<vector<long long> >& B)
{
    int n1=A.size() , m1 = A[0].size() , n2=B.size(), m2=B[0].size();
    vector<vector<long long>> C;
    if(m1!=n2) return C;
    C.resize(n1,vector<long long> (m2,0));
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

// raises matrix A to power p in logp time
vector<vector<long long>> pow(vector<vector<long long>> A ,int p) {
    auto res = A;
    for(auto &i:res) {
        for(auto &j:i) j=1;
    }
    while(p) {
        if(p&1) res=res*A;
        A=A*A;
        p>>=1;
    }
    return res;
}

// return nth fibonacci no. in O(logN) time
long long fib(long long n) {
    if(n<1) return 0;
    vector<vector<long long>> f0 = {{1,1},{1,0}};
    vector<vector<long long>> f1 = {{1},{0}};
    f0=pow(f0,n-1);
    f0 = f0*f1;
    return f0[0][0];
}

int main()
{
    cout<<fib(30);
    return 0;
}
// https://codeforces.com/problemset/problem/486/B
/*
Hint of this problem is presented in its statement. " where  is equal to 1 if some ai = 1, otherwise it is equal to 0."

To solve this problem, do 3 following steps:

Assign all aij (1 ≤ i ≤ m, 1 ≤ j ≤ n) equals to 1.
If some bij = 0, then do assignments: aik = atj = 0 (1 ≤ k ≤ n, 1 ≤ t ≤ m) (that means, assign all elements in row i and column j of matrix a to 0).
Then we have matrix a which need to find. Just check whether from matrix a, can we produce matrix b. If not, the answer is obviously "NO".
Complexity: We can implement this algorithm in O(m * n), but it's not neccesary since 1 ≤ m, n ≤ 100.
*/
#include<bits/stdc++.h>

using namespace std;

static const auto __optimize__ = []() {

std::ios::sync_with_stdio(false);

std::cin.tie(nullptr);

std::cout.tie(nullptr);

return 0;

}();

int main()
{
    int m=0, n=0;
    cin>>m>>n;
    int b[m][n]={{0}};
    int a[m][n]={{0}};
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>b[i][j];
            a[i][j]=1;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(!b[i][j]) {          
                int k=0;
                while(k<n) {
                    a[i][k++]=0;
                }
                k=0;
                while(k<m) {
                    a[k++][j]=0;
                }
            }
        }
    }
    string ans="YES";
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            int k=0 , bit_or=0;
            while(k<n && !bit_or) {
                bit_or|=a[i][k++];
            }
            k=0;
            while(k<m && !bit_or) {
                bit_or|=a[k++][j];
            }                    
            if(bit_or!=b[i][j]) {
                ans="NO";
                break;
            }
        }
        if(ans=="NO")
            break;
    }
    cout<<ans<<"\n";
    if(ans=="YES") {
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cout<<a[i][j];
            }
            cout<<'\n';
        }
    }                    
    return 0;
}
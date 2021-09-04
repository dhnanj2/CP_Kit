#include<bits/stdc++.h>

using namespace std;

    // take intersection of A & B , let it be temp, then take intersection of temp & C
    // time:O(min(n1,n2)+n3), space : O(n1+n2);
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i=0, j=0 ;
        vector<int> temp;
        while(i<n1 && j<n2) {
            if(A[i]<B[j]) i++;
            else if(A[i]>B[j]) j++;
            else {
                int n = temp.size();
                // remove duplicates in temp
                if((n &&temp[n-1]!=A[i])||(!n))
                    temp.push_back(A[i]);
                i++, j++;
            }
        }
        i=0 , j=0;
        vector<int> ans;
        while(i<temp.size() && j<n3) {
            if(temp[i]<C[j]) i++;
            else if(temp[i]>C[j]) j++;
            else {
                int n = ans.size();
                // remove duplicates in ans
                if((n && ans[n-1]!=C[j])||(!n))
                    ans.push_back(C[j]);
                i++, j++;
            }
        }
        return ans;
    }
    
int main()
{

return 0;
}    
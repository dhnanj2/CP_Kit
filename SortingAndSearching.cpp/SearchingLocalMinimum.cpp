// problem: https://codeforces.com/contest/1480/problem/C
/* soln :-
   to check for a[i] to be a local minimum we'll need a[i-1] & a[i+1], then the following cases arises:-
   1. a[i-1]>a[i]<a[i+1] , then a[i] is local  minimum
   2. a[i-1]>a[i]>a[i+1]... , then local minma lies in the right portion{i+2,i+3,....}
   3. a[i-1]<a[i]<a[i+1]... , then local minma lies in the left portion{.....,i-3,i-2}
   4. a[i-1]<a[i]>a[i+1 ]... , then a[i] is local maxima and the minima lies in either of left or right portion
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int beg=1,end=n;
    while(beg<=end) 
    {
        int mid=(beg+end)/2 ;
        cout<<"? "<<mid<<endl;
        int cur, l=INT_MAX, r= INT_MAX;
        cin>>cur;
        if(mid>1) {
            cout<<"? "<<mid-1<<endl;
            cin>>l;
        }
        if(mid<n) {
            cout<<"? "<<mid+1<<endl;
            cin>>r;
        }
        if(cur<min(l,r)) {              //case 1
            cout<<"! "<<mid<<endl;
            return 0;
        }
        else if(l<r) {                  //case 3 or 4
            end = mid-1;
        }
        else {                          //case 2 or 4
            beg = mid+1;
        }
    }
    return 0;
}
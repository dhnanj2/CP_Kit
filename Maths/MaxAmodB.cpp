/*
You are given two integers l and r, l≤r. Find the largest possible value of amodb over all pairs (a,b) of integers for which r≥a≥b≥l.

As a reminder, amodb is a remainder we get when dividing a by b. For example, 26mod8=2.

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤104), denoting the number of test cases. Description of the test cases follows.

The only line of each test case contains two integers l, r (1≤l≤r≤109).

Output
For every test case, output the largest possible value of amodb over all pairs (a,b) of integers for which r≥a≥b≥l.

Example
inputCopy
4
1 1
999999999 1000000000
8 26
1 999999999
outputCopy
0
1
12
499999999
Note
In the first test case, the only allowed pair is (a,b)=(1,1), for which amodb=1mod1=0.

In the second test case, the optimal choice is pair (a,b)=(1000000000,999999999), for which amodb=1.
*/


/*
It's not hard to see that if l≤⌊r2⌋+1, then rmod(⌊r2⌋+1)=⌊r−12⌋. It can be shown that the maximal possible answer.

At the same time, let the segment not contain number ⌊r2⌋+1, that is, l>⌊r2⌋+1. Then we can show that the maximal answer is rmodl=r−l.

Asymptotics: O(1) per test case.
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{   
    int t=1;
    cin>>t;
    while (t--)
    {
        ll l,r;
        cin>>l>>r;
        ll ans=(r-1)/2;
        if(r/2+1<l) ans=r%l;
        cout<<ans<<"\n";
    }    
    return 0;
}
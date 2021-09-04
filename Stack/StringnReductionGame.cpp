// https://www.geeksforgeeks.org/find-the-winner-of-the-game-to-win-by-erasing-any-two-consecutive-similar-alphabets/

#include<bits/stdc++.h>

using namespace std;

string findWinner(string s) 
{
    stack<char> stk;
    int cnt=0;
    for(auto i:s) {
        if(!stk.empty() && stk.top()==i) {
            cnt++;
            stk.pop();
        }
        else stk.push(i);
    }
    // cout<<cnt<<" ";
    return cnt%2?"Merry":"Pippin";
}

int main()
{

return 0;
}
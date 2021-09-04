#include<bits/stdc++.h>

using namespace std;

int score(int lo, int hi,unordered_map<int,int> &closed_at) {
    if(lo+1==hi) return 1;              // ()
    int p = closed_at[lo];              
    if(p==hi) return 2*score(lo+1,hi-1,closed_at); // (......)
    return score(lo,p,closed_at) + score(p+1,hi,closed_at);  // (....)(.....)
}

int scoreOfParentheses(string S) {
    stack<int> open;
    unordered_map<int,int> closed_at;
    for(auto i=0;i<S.size();i++) {
        if(S[i]=='(')
            open.push(i);
        else {
            int p = open.top();
            closed_at[p] = i;
            open.pop();
        }    
    }
    return score(0,S.size()-1,closed_at);
}

int main()
{

return 0;
}

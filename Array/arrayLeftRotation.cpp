#include<bits/stdc++.h>

using namespace std;

vector<int> rotLeft(vector<int> &a, int d) {
    // shiftng 'd' units left = shifting a.size()-d units right
    int k=a.size()-d;
    vector<int> b(a.size(),0);
    for (size_t i = 0; i < a.size(); i++)
    {
        int new_pos= (i+k)%a.size();
        b[new_pos] = a[i];
    }
    return b;
}

int main()
{

    return 0;
}
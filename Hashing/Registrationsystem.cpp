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
    int n=0;
    cin>>n;
    map<string,int> present;
    while (n--)
    {
        string s;
        cin>>s;
        if(!present[s]) {
            present[s]=1;
            cout<<"OK"<<"\n";
            continue;
        }
        auto str = s+to_string(present[s]);
        present[s]+=1;
        cout<<str<<"\n";
    }
    return 0;
}
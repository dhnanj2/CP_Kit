//          PROBLEM: https://www.codechef.com/problems/HW2B

#include<bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int n=0;
	cin>>n;
	vector<int> balls(n,0);
	map<int,vector<int>> pos;
	int sum=0;
	for(int i=0;i<n;i++) {
	    cin>>balls[i];
	    sum+=balls[i];
	    pos[balls[i]].push_back(i+1);
	}
	int ind_sum=sum/(n/2);
	map<int,bool> given;
	for(auto i=0;i<balls.size();i++) {
	    if(given[i]) 
	        continue;
        given[i]=true;
        cout<<i<<" ";
        auto vec = pos[ind_sum-balls[i]];
        for(auto i:vec) {
            if(!given[i]) {
                cout<<i<<endl;
                given[i]=true;
                break;
            }
        }
	}
	return 0;
}

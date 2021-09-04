/*
Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
 
Example:
Input
3
5
10
2
 
Output
120
3628800
2
*/

#include<bits/stdc++.h>

using namespace std;
 
string operator*(string a,string b) {
    int flg=1;
    if(a[0]=='-') {
        flg*=-1;
        a.erase(a.begin());
    }
    if(b[0]=='-') {
        flg*=-1;
        b.erase(b.begin());
    }
    string n1 ,n2; 
    a.size()<b.size()? (n1=a , n2=b) : (n1=b , n2=a);
    vector<string> prods;
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    for(auto i:n1) {    
        int carry = 0;
        string prod;
        for(auto j:n2) {
            int a = (int)i-48;
            int b = (int)j-48;
            int p = a*b+carry;
            prod+=to_string(p%10);
            carry = p>9 ? p/10 : 0;
        }
        // reverse(prod.begin(),prod.end());
        if(carry>0 )
            prod+=to_string(carry);
        // cout<<prod<<" ";    
        prods.push_back(prod);
    }
    int n=0;
    for(int i=0;i<prods.size();i++) {
        prods[i].insert(prods[i].begin(),i,' ');
        n = max(n,(int)prods[i].size());
    }
    string ans;
    int carry=0;
    for(int i=0;i<n;i++) {
        int  sum=0;
        for(int j=0;j<prods.size();j++) {
            if(i<prods[j].size() && prods[j][i]!=' ')
                sum += (int)prods[j][i]-48;
        }
        ans+=to_string((sum+carry)%10);
        carry = (sum+carry)>9 ? (sum+carry)/10 : 0;
        // cout<<ans<<" "<<carry<<"\n";
    }
    if(carry>0)
        ans+=to_string(carry);
    reverse(ans.begin(),ans.end());
    int i=0;
    while(i<ans.size() && ans[i]=='0') i++;
    if(i>=ans.size()){
        return "0";
    }
    ans = ans.substr(i);
    if(flg<0) {
        ans.insert(ans.begin(),'-');
    }
    return ans;
}

int main()
{
    int t=0;
	cin>>t;
    unordered_map<int,string> stored_fact;
	while(t--) {
	    int n=0;
	    cin>>n;
        if(!stored_fact[n].empty()) 
        { cout<<stored_fact[n]<<"\n" ; 
          continue;
        }
	    string fact="1";
	    for(int i=2;i<=n;i++) {
            fact = fact * to_string(i);
            stored_fact[i]=fact;
	    }
	    cout<<fact<<"\n";
	}
    // cout<<to_string(39916800)*to_string(12);
    return 0;
}
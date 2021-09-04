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
    
    return 0;
}
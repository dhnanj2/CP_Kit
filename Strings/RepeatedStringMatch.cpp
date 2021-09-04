#include<bits/stdc++.h>

using namespace std;

int *pre_kmp(string pattern)
{
	int size = pattern.size();
	int *pie=new int [size];
	pie[0] = 0;
	int k=0;
	for(int i=1;i<size;i++)
	{
		while(k>0 && pattern[k] != pattern[i] )
		{
			k=pie[k-1];
		}
		if( pattern[k] == pattern[i] )
		{
			k=k+1;
		}
		pie[i]=k;
	}
	
	return pie;
}

// Searching , overall Time : O(N+M) , space : O(M)
int kmp(string text,string pattern)
{
	int* pie=pre_kmp(pattern);
	for(int i=0;i<pattern.size();i++) cout<<pie[i];
	int matched_pos=0;
	for(int current=0; current< text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.length()) )
		{
			return current - (pattern.length() -1);
			matched_pos = pie[matched_pos-1];
		}
	}
	delete[] pie;	
    return -1;
}

int repeatedStringMatch(string A, string B){
    int ans=1;
    string s=A;
    while(s.size() < B.size()) {
        s+=A;
        ans++;
    }     
    if(kmp(s,B)>=0) return ans;
    s+=A;
    ans++;
    if(kmp(s,B)>=0) return ans;
    return -1;
}

int main()
{

    return 0;
}
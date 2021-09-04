#include<bits/stdc++.h>

using namespace std;

unordered_set<string> s;
    
string helper(Node* root) {
    if(!root) return "$";
    string l=helper(root->left);
    string r=helper(root->right);
    if(l.empty() || r.empty()) return "";
    string str=to_string(root->data)+l+r;
    if(str.size()>3 && s.find(str)!=s.end()) return "";
    s.insert(str);
    return str;
}
    
int dupSub(Node *root) {
    return helper(root).empty();    
}

int main()
{

    return 0;
}
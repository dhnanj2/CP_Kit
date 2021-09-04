#include<bits/stdc++.h>

using namespace std;

vector<int> findSpiral(Node *root)
{
    stack<Node*> s1,s2;
    vector<int> ans;
    if(!root)return ans;
    s1.push(root);
    while(s1.size() || s2.size()) {
        while(s1.size()) {
            auto n=s1.top();
            ans.push_back(n->data);
            if(n->right)s2.push(n->right);
            if(n->left)s2.push(n->left);
            s1.pop();
        }
        while(s2.size()) {
            auto n=s2.top();
            ans.push_back(n->data);
            if(n->left)s1.push(n->left);
            if(n->right)s1.push(n->right);
            s2.pop();
        }
    }
    return ans;
}

int main()
{

    return 0;
}
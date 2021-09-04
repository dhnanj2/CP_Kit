#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

void preorder(node * root) {
    stack<node*> stk;
    auto n=root;
    stk.push(root);
    while(!stk.empty()) {
        auto n=stk.top();
        stk.pop();
        while(n) {
            cout<<n->data<<" ";
            stk.push(n->right);
            n=n->left;
        }    
    }
}

void inorder(node * root) {
    stack<node*> stk;
    auto n=root;
    while(n) {
        stk.push(n);
        if(!n && !stk.empty()) {
            node *t = stk.top();
            cout<<t->data<<" ";
            n=t->right;
        }
        else if(n) n=n->left;
    }
}

int main()
{
    
    return 0;
}
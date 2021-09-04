/*
Given a binary tree of size  N, a node and a positive integer k., 
Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. 
If there does not exist any such ancestor then return -1.
*/
#include<bits/stdc++.h>

using namespace std;

// returns dist b/w node "root" & node "n" if present else returns -1
int getHeight(Node* root,int n) {
    if(!root) return -1;        
    if(root->data==n) return 0;
    int h=getHeight(root->left,n);
    if(h>=0) return h+1;
    h=getHeight(root->right,n);
    if(h>=0) return h+1;
    return -1;
}

int kthAncestor(Node *root, int k, int node)
{
    if(!root)return -1;
    if(getHeight(root,node)==k) return root->data;
    int l=kthAncestor(root->left,k,node);
    if(l>=0)return l;
    l=kthAncestor(root->right,k,node);
    if(l>=0)return l;
    return -1;
}

int main()
{

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* LCA(TreeNode* root,int p,int q) {
    if(root->val==p || root->val==q) return root;
    TreeNode *lft=NULL, *rt=NULL;
    if(root->left) lft=LCA(root->left,p,q);
    if(root->right) rt=LCA(root->right,p,q);
    if(lft && rt) return root;
    if(lft) return lft;
    return rt;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return LCA(root,p->val,q->val);
}

int main()
{

    return 0;
}
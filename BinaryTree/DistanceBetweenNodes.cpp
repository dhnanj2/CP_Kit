#include<bits/stdc++.h>

using namespace std;

int dist(Node* src,int dest,int lvl=0) {
    if(!src) return INT_MAX;
    if(src->data==dest)return lvl;
    return min(dist(src->left,dest,lvl+1),dist(src->right,dest,lvl+1));
}
   
Node* LCA(Node* root,int p,int q) {
    if(root->data==p || root->data==q) return root;
    Node *lft=NULL, *rt=NULL;
    if(root->left) lft=LCA(root->left,p,q);
    if(root->right) rt=LCA(root->right,p,q);
    if(lft && rt) return root;
    if(lft) return lft;
    return rt;
}

int findDist(Node* root, int a, int b) {
    int lca=LCA(root,a,b)->data;
    return dist(root,a)+dist(root,b)-2*dist(root,lca);    
}

int main()
{

return 0;
}
/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/
#include<bits/stdc++.h>

using namespace std;

TreeNode* solve(vector<int>& a,int st,int end) {
    if(st>=end) return NULL;
    int m=(st+end)/2;
    TreeNode* n=new TreeNode(a[m]);
    n->left = solve(a,st,m);
    n->right = solve(a,m+1,end);
    return n;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums,0,nums.size());
}

int main()
{

return 0;
}
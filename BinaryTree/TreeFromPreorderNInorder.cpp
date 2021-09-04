#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Algorithm: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2) Create a new tree node tNode with the data as the picked element. 
3) Find the picked element’s index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6) return tNode.
*/
class Solution {
public:
    vector<int> in,pre;
    
    int index(int target) {
        for(int i=0;i<in.size();i++) {
            if(in[i]==target) return i;
        }
        return -1;
    }
    int p=0;
    TreeNode* fun(int st, int end) {
        if(st>end || p>=pre.size()) return NULL;
        // cout<<pre[p]<<" ";
        int i=index(pre[p++]);
        TreeNode* root = new TreeNode(in[i],fun(st,i-1),fun(i+1,end));
        // if(st==end) return root;
        // root->left=fun(st,i-1);
        // root->right=fun(i+1,end);            
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre=preorder;
        in =inorder;
        return fun(0,in.size()-1);
    }
};

int main()
{

return 0;
}
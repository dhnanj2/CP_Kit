#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // function to return height of node "root"
    int height(Node* root) {
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(!root) return 0;
        int dia=1+height(root->right)+height(root->left);
        return max({diameter(root->left),diameter(root->right),dia});
    }
};

int main()
{

    return 0;
}
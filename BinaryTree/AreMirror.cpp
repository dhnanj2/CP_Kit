// Given Two Binary Tree , return true if they both are mirror image of each other.
 
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

class Solution
{
    public:
    
    bool isEqual(Node* a,Node *b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->data!=b->data) return false;
        return isEqual(a->left,b->right)&&isEqual(a->right,b->left);
    }
    
    int areMirror(Node* a, Node* b) {
        // mirror(b);
        return isEqual(a,b);
    }

};

int main()
{
    
    return 0;
}
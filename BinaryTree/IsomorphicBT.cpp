#include<bits/stdc++.h>

using namespace std;

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    void flip(Node* t) {
        if(!t)return;
        auto l=t->left;
        auto r=t->right;
        t->left=r;
        t->right=l;
    }
    
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(!root1) {
            return root2==NULL;
        }if(!root2) {
            return root1==NULL;
        }
        if(root1->data!=root2->data) return false;
        if(!isIsomorphic(root1->left,root2->left) || !isIsomorphic(root1->right,root2->right)) {
            flip(root2);
            return isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right);
        }
        return true;
    }
};

int main()
{

return 0;
}
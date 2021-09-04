#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

vector<int> rightView(Node *root)
{
   queue<Node*> q;
   vector<int> ans;
   if(!root) return ans;
   q.push(root);
   q.push(NULL);
   while(!q.empty()) {
        auto n=q.front();
        int a=-1;
       while(n) {
            a=n->data;
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
            q.pop();
            n=q.size()?q.front():NULL;
       }
       if(a>=0) {
            ans.push_back(a);
            q.push(NULL);
       }
       q.pop();
   }
}

int main()
{

    return 0;
}
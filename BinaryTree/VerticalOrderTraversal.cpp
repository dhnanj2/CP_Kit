/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/
#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
 struct Node {
     int data;
     Node *left;
     Node *right;
     Node() : data(0), left(nullptr), right(nullptr) {}
     Node(int x) : data(x), left(nullptr), right(nullptr) {}
     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

// Time : O(N), n->no. of nodes
vector<int> verticalTraversal(Node* root) {
    queue<pair<Node*,int>> q;
    map<int,vector<int>> m;
    vector<int> ans;
    if(!root) return ans;
    q.push(make_pair(root,0));
    while(!q.empty()) {
        auto n=q.front().first;
        int hl=q.front().second;
        m[hl].push_back(n->data);
        if(n->left) q.push(make_pair(n->left,hl-1));
        if(n->right) q.push(make_pair(n->right,hl+1));
        q.pop();
    }
    for(auto i:m) {
        for(auto j:i.second) {
            ans.push_back(j);
        }
    }
    return ans;
}

int main()
{

    return 0;
}
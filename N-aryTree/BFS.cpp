#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> t;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            auto n=q.front();
            q.pop();
            if(!n) {
                ans.push_back(t);
                t.clear();
                if(!q.empty()) q.push(NULL);
            }else  {
                t.push_back(n->val);
                for(auto i:n->children) {
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
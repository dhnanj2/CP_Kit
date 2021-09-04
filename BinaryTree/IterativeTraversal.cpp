/*
the method illustrared below can be used to traverse a binary tree in any dfs order iteratively with a little variation in code.
the method illustrared below is based on iterative simulation of the corresponding recursive soln.
infact using this method one can simultaneously traverse in all the three orders.
*/
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> inOrder(Node* root)
{
    vector<int> d;
    d.clear();
    stack<pair<Node*,int>> st;
    st.push(make_pair(root,0));
    while(!st.empty()) {
        auto &p=st.top();
        Node* n = p.first;
        int &x = p.second;
        if(!n) st.pop();
        else if(!x) {
            st.push(make_pair(n->left,0));
        }else if(x==1) {
            d.push_back(n->data);
            st.push(make_pair(n->right,0));
        }else {
            st.pop();
        }
        x++;
    }
    return d;
}

vector<int> preOrder(Node* root)
{
    vector<int> d;
    d.clear();
    stack<pair<Node*,int>> st;
    st.push(make_pair(root,0));
    while(!st.empty()) {
        auto &p=st.top();
        Node* n = p.first;
        int &x = p.second;
        if(!n) st.pop();
        else if(!x) {
            d.push_back(n->data);
            st.push(make_pair(n->left,0));
        }else if(x==1) {
            st.push(make_pair(n->right,0));
        }else {
            st.pop();
        }
        x++;
    }
    return d;
}

vector<int> postOrder(Node* root)
{
    vector<int> d;
    d.clear();
    stack<pair<Node*,int>> st;
    st.push(make_pair(root,0));
    while(!st.empty()) {
        auto &p=st.top();
        Node* n = p.first;
        int &x = p.second;
        if(!n) st.pop();
        else if(!x) {
            st.push(make_pair(n->left,0));
        }else if(x==1) {
            st.push(make_pair(n->right,0));
        }else {
            d.push_back(n->data);
            st.pop();
        }
        x++;
    }
    return d;
}

void traverse(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post) {
    stack<pair<Node*,int>> st;
    st.push(make_pair(root,0));
    while(!st.empty()) {
        auto &p=st.top();
        Node* n = p.first;
        int &x = p.second;
        if(!n) st.pop();
        else if(!x) {
            pre.push_back(n->data);
            st.push(make_pair(n->left,0));
        }else if(x==1) {
            in.push_back(n->data);
            st.push(make_pair(n->right,0));
        }else {
            post.push_back(n->data);
            st.pop();
        }
        x++;
    }
}

int main()
{

    return 0;
}
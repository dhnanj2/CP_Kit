#include<bits/stdc++.h>

using namespace std;


Node* Build(int val,vector<int> &l,vector<int> &r) {
    Node* n = new Node(val);
    if(l[val]>=0) {
        n->left=Build(l[val],l,r);
    }if(r[val]>=0) {
        n->right=Build(r[val],l,r);
    }
    return n;
}

Node *createTree(int p[], int N)
{
    vector<int> l(N,-1);
    vector<int> r(N,-1);
    int root;
    for(int i=0;i<N;i++) {
        if(p[i]>=0) {
            if(l[p[i]]<0) l[p[i]]=i;
            else r[p[i]]=i;
        }else {
            root=i;
        }
    }
    return Build(root,l,r);
}

int main()
{

    return 0;
}
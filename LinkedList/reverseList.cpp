#include<bits/stdc++.h>

using namespace std;

// Time : O(N) ,space: O(1)
// uses 3 pointers technique to  reverse the given liked list
struct Node* reverseList(struct Node *head)
{
    auto cur=head;
    struct Node* prev=NULL;
    while(cur!=NULL) {
        auto next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}

int main()
{

    return 0;
}
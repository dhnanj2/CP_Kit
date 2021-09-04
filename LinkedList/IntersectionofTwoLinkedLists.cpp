#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// hashing, Time:O(n+m) , space:O(n+m)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, bool> vis;
    auto t1 = headA , t2=headB;
    while(t1 && t2) {
        if(vis[t2])
            return t2;
        vis[t2]=true;
        if(vis[t1])
            return t1;
        vis[t1]=true;
        t1=t1->next;
        t2=t2->next;
    }
    while(t1) {
        if(vis[t1])
            return t1;
        t1=t1->next;
    }
    while(t2) {
        if(vis[t2])
            return t2;
        t2=t2->next;
    }
    return nullptr;
}

// 2Pointer , Time:O(n+m) , space:O(1)
/*
We know that we've now fully optimized the time complexity: it's impossible to do better than O(N + M)O(N+M) as, in the worst case, we'll need to look at every node at least once. 
But, is there a way we can get the space complexity down to O(1)O(1) while maintaining that awesome O(N + M)O(N+M) time complexity that we just achieved? It turns out that there is!

Observe that while list A and list B could be different lengths, that the shared "tail" following the intersection has to be the same length.

Imagine that we have two linked lists, A and B, and we know that their lengths are NN and MM respectively (these can be calculated with O(1)O(1) space and in time proportional to the length of the list). We'll imagine that N = 5N=5 and M = 8M=8.

Two linked lists with question marks on their nodes. The first is 5 nodes long, and the second is 8 nodes long.

Because the "tails" must be the same length, we can conclude that if there is an intersection, then the intersection node will be one of these 5 possibilities.

The two linked lists from above with arrows showing how the last 5 nodes of each list could be a match.

So, to check for each of these pairs, we would start by setting a pointer at the start of the shorter list, and a pointer at the first possible matching node of the longer list. The position of this node is simply the difference between the two lengths, that is, |M - N|∣M−N∣.

The two linked lists from above with a p1 pointer at the head of the first, and a p2 pointer at the 4th node of the second.

Then, we just need to step the two pointers through the list, each time checking whether or not the nodes are the same.
*/

int getLength(ListNode *head) {
    auto i=head;
    int l=0;
    while(i) {
        l++;
        i=i->next;
    }
    return l;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int la = getLength(headA);
    int lb = getLength(headB);
    int dif=abs(la-lb);
    auto p1=headA;  //pointing to shorter list
    auto p2=headB;  //pointing to longer list
    if(la>lb) {
        p1 = headB;
        p2 = headA;
    }
    while (dif--)
    {   
        p2 = p2->next;
    }
    while(p1 && p2) {
        if(p1==p2) return p1;
        p1=p1->next;
        p2=p2->next;
    }
    return NULL;
}

int main()
{

    return 0;
}
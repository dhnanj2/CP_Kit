//  Floyd' tortoise and hare algorithm to find the cycle entrance of linked list
// related problems : https://leetcode.com/problems/linked-list-cycle-ii/
// related problems : https://leetcode.com/problems/find-the-duplicate-number/
// Explanation : https://leetcode.com/problems/find-the-duplicate-number/solution/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    auto tortoise = head , hare = head;
    // Phase 1
    while (hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(hare == tortoise)
            break;
    }
    if(!hare || !hare->next)
        return NULL;
    tortoise = head;
    // Phase 2
    while (tortoise != hare)
    {
        tortoise = tortoise->next;
        hare = hare->next;
    }
    return hare;
}

int main()
{

    return 0;
}

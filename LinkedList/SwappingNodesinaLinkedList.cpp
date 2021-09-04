/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

Example 3:
Input: head = [1], k = 1
Output: [1]

Example 4:
Input: head = [1,2], k = 1
Output: [2,1]

Example 5:
Input: head = [1,2,3], k = 2
Output: [1,2,3]

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
   Hide Hint #1  
We can transform the linked list to an array this should ease things up
   Hide Hint #2  
After transforming the linked list to an array it becomes as easy as swapping two integers in an array then rebuilding the linked list
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Time:O(N), space:O(1)
class Solution {
public:
    int len(ListNode* head) {
        auto it=head;
        int ans=0;
        while(it) {
            ans++;
            it=it->next;
        }
        return ans;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        auto l=len(head);
        if(l==1) return head;
        int k_=l-k+1;
        if(k_<k) swap(k,k_);
        auto it=head;
        int i=0;
        while(it) {
            i++;
            if(i<k) {
                it=it->next;
                continue;
            }
            auto t=it;
            while(k_>k) {
                t=t->next;
                k++;
            }
            swap(t->val,it->val);
            break;
        }
        return head;
    }
};
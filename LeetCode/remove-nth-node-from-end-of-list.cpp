/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(ListNode* current, int& n, int& sz) {
        if (current == NULL) {
            return;
        }

        traverse(current->next, n, sz);
        ++sz;
        
        if ((sz - 1) == n) {
            current->next = current->next->next;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        traverse(head, n, sz);
        return sz == n ? head->next : head;
    }
};
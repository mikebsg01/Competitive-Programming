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
    int traverse(ListNode* current, int n, int level) {
        if (current == NULL) {
            return 0;
        }

        int idx = 1 + traverse(current->next, n, level + 1);
        
        if ((idx - 1) == n) {
            current->next = current->next->next;
        }
        
        return idx;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = traverse(head, n, 1);
        return sz == n ? head->next : head;
    }
};
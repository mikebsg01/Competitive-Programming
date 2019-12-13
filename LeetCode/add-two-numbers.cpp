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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        int a, b, sum = 0, carry = 0;
        bool first = true;

        while (l1 or l2 or carry > 0) {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            sum = a + b + carry;
            carry = sum / 10;
            sum %= 10;
            
            if (first) {
                ans->val = sum;
                first = false;
            } else {
                ans->next = new ListNode(sum);
                ans = ans->next;
            }
            
            if (l1)
                l1 = l1->next;
            
            if (l2)
                l2 = l2->next;
        }
        
        return head;
    }
};
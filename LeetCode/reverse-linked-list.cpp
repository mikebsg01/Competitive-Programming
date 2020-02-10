#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp, *tail = NULL;

        while (head) {
            tmp = head->next;
            head->next = tail;
            tail = head;
            head = tmp;
        }

        return tail;
    }
};

void traverse(ListNode* current) {
    while (current) {
        cout << current->val << endl;
        current = current->next;
    }
}

int main() {
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    traverse(list);

    Solution solution;
    ListNode* reversedList = solution.reverseList(list);
    traverse(reversedList);
    return 0;
}
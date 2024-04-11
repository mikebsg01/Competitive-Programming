#include <iostream>
using namespace std;

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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasNextElement(ListNode* node) {
        return node->next != nullptr;
    }

    bool isElementEqual(ListNode* a, ListNode* b) {
        return a->val == b->val;
    }

    bool isNextElementEqual(ListNode* node) {
        return isElementEqual(node, node->next);
    }

    bool isNextElementDuplicated(ListNode* node) {
        return hasNextElement(node) && isNextElementEqual(node);
    }

    ListNode* getNextElementNotDuplicated(ListNode* node) {
        ListNode *current = node, *temp;
        while (isNextElementDuplicated(current)) {
            temp = current->next;
            /* cout << "Deleting " << current->val << " from list - address: " << current << endl; */
            delete current;
            current = temp;
        }
        return current->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode    *current = head,
                    *left = head,
                    *nextElementNotDuplicated;

        while (current != nullptr) {
            if (isNextElementDuplicated(current)) {
                nextElementNotDuplicated = getNextElementNotDuplicated(current);
                
                if (current == head) {
                    current = nextElementNotDuplicated;
                    head = current;
                    left = head;
                } else {
                    current = nextElementNotDuplicated;
                    left->next = current;
                }
            } else {
                left = current;
                current = current->next;
            }
        }

        return head;
    }
};

void printList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, x;
    ListNode *head, *current, *ans;
    Solution solution;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (i != 0) {
            current->next = new ListNode(x);
            current = current->next;
        } else {
            head = new ListNode(x);
            current = head;
        }
    }

    cout << "Original list: ";
    printList(head);
    
    ans = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(ans);
    return 0;
}
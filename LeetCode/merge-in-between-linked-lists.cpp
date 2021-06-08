#include <iostream>
#define dd(x) cout << #x << ": " << x << "\n";
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* list) {
    while (list != NULL) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev, *left = NULL, *right = NULL, *current = list1;
        int idx = 0;

        while (current != NULL) {
            if (idx == (a - 1)) {
                left = current;
            } else if (idx == (b + 1)) {
                right = current;
                break;
            }

            prev = current;
            current = current->next;

            if (idx >= a and idx <= b) {
                delete prev;
            } 

            ++idx;
        }

        left->next = list2;
        current = left->next;

        while(current->next != NULL) {
            current = current->next;
        }
        current->next = right;

        return list1;
    }
};

void case1() {
    int a = 2, b = 4;

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(6);
    list1->next->next->next->next->next->next = new ListNode(7);

    ListNode* list2 = new ListNode(11);
    list2->next = new ListNode(10);
    list2->next->next = new ListNode(9);
    list2->next->next->next = new ListNode(8);
    
    printList(list1);
    dd(a);
    dd(b);
    printList(list2);
    
    Solution s;
    list1 = s.mergeInBetween(list1, a, b, list2);

    printList(list1);
    printList(list2);
}

void case2  () {
    int a = 1, b = 1;

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(11);
    list2->next = new ListNode(10);
    list2->next->next = new ListNode(9);
    list2->next->next->next = new ListNode(8);
    
    printList(list1);
    dd(a);
    dd(b);
    printList(list2);
    
    Solution s;
    list1 = s.mergeInBetween(list1, a, b, list2);

    printList(list1);
    printList(list2);
}

int main() {
    case1();
    cout << endl;
    case2();
    return 0;
}
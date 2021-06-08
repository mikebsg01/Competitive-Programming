#include <iostream>
#include <tuple>
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

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *current = head, 
            *target1, 
            *target2;

        while (k--) {
            target1 = current;
            current = current->next;
        }

        current = target1;
        target2 = head;

        while (current->next != NULL) {
            current = current->next;
            target2 = target2->next;
        }

        swap(target1->val, target2->val);
        return head;
    }
};


void case1() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(6);
    list1->next->next->next->next->next->next = new ListNode(7);
    printList(list1);

    Solution s;
    list1 = s.swapNodes(list1, 1);
    printList(list1);
    
    list1 = s.swapNodes(list1, 3);
    printList(list1);
}

void case2() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(6);
    list1->next->next->next->next->next->next = new ListNode(7);
    printList(list1);

    Solution s;
    list1 = s.swapNodes(list1, 2);
    printList(list1);
}

int main() {
    case1();
    cout << endl;
    case2();
    cout << endl;
    return 0;
}

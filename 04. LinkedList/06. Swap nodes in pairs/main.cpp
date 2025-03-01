#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = head->next;
    ListNode* prev = NULL;

    while (head && head->next) {
        ListNode* first = head;
        ListNode* second = head->next;

        first->next = second->next;
        second->next = first;

        if (prev) prev->next = second;
        prev = first;
        head = first->next;
    }

    return newHead;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    head = swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(head);

    return 0;
}

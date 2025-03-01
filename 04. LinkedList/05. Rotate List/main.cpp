#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find the length of the linked list
    int length = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Compute effective rotations
    k = k % length;
    if (k == 0) return head;

    // Find the new head position (length - k)
    ListNode* cur = head;
    for (int i = 1; i < length - k; i++) {
        cur = cur->next;
    }

    // Break the list and reconnect
    ListNode* newHead = cur->next;
    cur->next = NULL;
    tail->next = head;
    
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
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);
    
    cout << "List after rotating by " << k << ": ";
    printList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int count = 0;

    // Count k nodes
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    // If there are at least k nodes, reverse them
    if (count == k) {
        ListNode* prev = NULL, *curr = head, *next = NULL;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Recursively process the remaining nodes
        head->next = reverseKGroup(next, k);
        return prev;
    }

    return head; // Return the original head if less than k nodes remain
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
    head = reverseKGroup(head, k);

    cout << "List after reversing in k-groups: ";
    printList(head);

    return 0;
}

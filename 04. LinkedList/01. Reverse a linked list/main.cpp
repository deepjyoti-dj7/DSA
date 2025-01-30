#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Iterative approach to reverse a linked list
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next; // Store next node
        current->next = prev;  // Reverse the link
        prev = current;  // Move prev forward
        current = nextNode;  // Move current forward
    }

    return prev; // New head
}

// Recursive approach to reverse a linked list
ListNode* reverseListRecursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: return last node as new head
    }

    ListNode* newHead = reverseListRecursive(head->next); // Reverse rest of list
    head->next->next = head; // Reverse current node's link
    head->next = nullptr; // Set current node's next to null

    return newHead; // Return new head
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Iterative Reverse
    head = reverseListIterative(head);
    cout << "Reversed List (Iterative): ";
    printList(head);

    // Reverse back using Recursive method
    head = reverseListRecursive(head);
    cout << "Reversed List (Recursive): ";
    printList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    
    while (cur) {
        while (cur->next && cur->val == cur->next->val)
            cur->next = cur->next->next;  // Skip duplicate node
        
        cur = cur->next; // Move forward
    }
    
    return head;
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);
    
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

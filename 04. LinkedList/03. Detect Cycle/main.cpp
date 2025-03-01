#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) return true; // Cycle detected
    }
    
    return false; // No cycle
}

// Helper function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* temp = head;
    ListNode* cycleNode = nullptr;
    int index = 0;
    
    while (temp->next) {
        if (index == pos) cycleNode = temp;
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode; // Create cycle
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    createCycle(head, 1); // Cycle at position 1
    
    cout << (hasCycle(head) ? "Cycle detected" : "No cycle") << endl;
    
    return 0;
}

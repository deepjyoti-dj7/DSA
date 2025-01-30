class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

// Iterative method
function reverseListIterative(head) {
    let prev = null;
    let current = head;

    while (current !== null) {
        let nextNode = current.next; // Store next node
        current.next = prev; // Reverse link
        prev = current; // Move prev forward
        current = nextNode; // Move current forward
    }

    return prev; // New head
}

// Recursive method
function reverseListRecursive(head) {
    if (head === null || head.next === null) {
        return head; // Base case: return last node as new head
    }

    let newHead = reverseListRecursive(head.next);
    head.next.next = head; // Reverse link
    head.next = null; // Set current node's next to null

    return newHead; // Return new head
}

// Utility function to print linked list
function printList(head) {
    let output = "";
    while (head !== null) {
        output += head.val + " -> ";
        head = head.next;
    }
    console.log(output + "NULL");
}

function main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    let head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(4);
    head.next.next.next.next = new ListNode(5);
    
    console.log("Original List:");
    printList(head);
    
    // Iterative Reverse
    head = reverseListIterative(head);
    console.log("Reversed List (Iterative):");
    printList(head);
    
    // Reverse back using Recursive method
    head = reverseListRecursive(head);
    console.log("Reversed List (Recursive):");
    printList(head);
}

main();

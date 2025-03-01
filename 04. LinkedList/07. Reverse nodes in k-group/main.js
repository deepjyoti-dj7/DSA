class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function reverseKGroup(head, k) {
    let temp = head, count = 0;

    // Count k nodes
    while (temp && count < k) {
        temp = temp.next;
        count++;
    }

    if (count === k) {
        let prev = null, curr = head, next = null;
        for (let i = 0; i < k; i++) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        // Recursively process the next k nodes
        head.next = reverseKGroup(temp, k);
        return prev;
    }

    return head; // If fewer than k nodes remain, return the head as is
}

// Utility function to print a linked list
function printList(head) {
    let result = "";
    while (head) {
        result += head.val + " -> ";
        head = head.next;
    }
    result += "NULL";
    console.log(result);
}

// Main function
function main() {
    let head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(4);
    head.next.next.next.next = new ListNode(5);

    console.log("Original List:");
    printList(head);

    let k = 2;
    head = reverseKGroup(head, k);

    console.log("List after reversing in k-groups:");
    printList(head);
}

// Run main function
main();

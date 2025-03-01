class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function rotateRight(head, k) {
    if (!head || !head.next || k === 0) return head;

    // Find the length of the linked list
    let length = 1;
    let tail = head;
    while (tail.next) {
        tail = tail.next;
        length++;
    }

    // Compute effective rotations
    k = k % length;
    if (k === 0) return head;

    // Find the new head position (length - k)
    let cur = head;
    for (let i = 1; i < length - k; i++) {
        cur = cur.next;
    }

    // Break the list and reconnect
    let newHead = cur.next;
    cur.next = null;
    tail.next = head;

    return newHead;
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
    head = rotateRight(head, k);

    console.log(`List after rotating by ${k}:`);
    printList(head);
}

// Run main function
main();

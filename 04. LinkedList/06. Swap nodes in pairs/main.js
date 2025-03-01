class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function swapPairs(head) {
    if (!head || !head.next) return head;

    let newHead = head.next;
    let prev = null;

    while (head && head.next) {
        let first = head;
        let second = head.next;

        first.next = second.next;
        second.next = first;

        if (prev) prev.next = second;
        prev = first;
        head = first.next;
    }

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

    console.log("Original List:");
    printList(head);

    head = swapPairs(head);

    console.log("List after swapping pairs:");
    printList(head);
}

// Run main function
main();

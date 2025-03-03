class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function deleteDuplicates(head) {
    let cur = head;

    while (cur) {
        while (cur.next && cur.val === cur.next.val)
            cur.next = cur.next.next; // Skip duplicate node
        
        cur = cur.next; // Move forward
    }

    return head;
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
    head.next = new ListNode(1);
    head.next.next = new ListNode(2);
    head.next.next.next = new ListNode(3);
    head.next.next.next.next = new ListNode(3);

    console.log("Original List:");
    printList(head);

    head = deleteDuplicates(head);

    console.log("List after removing duplicates:");
    printList(head);
}

// Run main function
main();

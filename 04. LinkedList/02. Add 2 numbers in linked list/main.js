class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function addTwoNumbers(l1, l2) {
    let dummy = new ListNode(0);
    let current = dummy;
    let carry = 0;

    while (l1 || l2 || carry) {
        let sum = carry;
        if (l1) { sum += l1.val; l1 = l1.next; }
        if (l2) { sum += l2.val; l2 = l2.next; }
        
        carry = Math.floor(sum / 10);
        current.next = new ListNode(sum % 10);
        current = current.next;
    }

    return dummy.next;
}

// Helper function to print linked list
function printList(head) {
    let output = [];
    while (head) {
        output.push(head.val);
        head = head.next;
    }
    console.log(output.join(" -> ") + " -> NULL");
}

// Main function
function main() {
    let l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    let l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    let result = addTwoNumbers(l1, l2);
    printList(result);
}

// Run main function
main();

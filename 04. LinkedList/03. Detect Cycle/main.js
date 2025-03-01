class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function hasCycle(head) {
    let slow = head, fast = head;

    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;

        if (slow === fast) return true; // Cycle detected
    }

    return false; // No cycle
}

// Helper function to create a cycle
function createCycle(head, pos) {
    if (pos === -1) return;
    let temp = head, cycleNode = null, index = 0;

    while (temp.next) {
        if (index === pos) cycleNode = temp;
        temp = temp.next;
        index++;
    }
    temp.next = cycleNode; // Create cycle
}

// Main function
function main() {
    let head = new ListNode(3);
    head.next = new ListNode(2);
    head.next.next = new ListNode(0);
    head.next.next.next = new ListNode(-4);

    createCycle(head, 1); // Cycle at position 1

    console.log(hasCycle(head) ? "Cycle detected" : "No cycle");
}

// Run main function
main();

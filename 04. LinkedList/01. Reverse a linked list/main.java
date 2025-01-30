class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class main {
    // Iterative method
    public static ListNode reverseListIterative(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode nextNode = current.next; // Store next node
            current.next = prev;  // Reverse link
            prev = current;  // Move prev forward
            current = nextNode;  // Move current forward
        }

        return prev; // New head
    }

    // Recursive method
    public static ListNode reverseListRecursive(ListNode head) {
        if (head == null || head.next == null) {
            return head; // Base case: return last node as new head
        }

        ListNode newHead = reverseListRecursive(head.next);
        head.next.next = head; // Reverse link
        head.next = null; // Set current node's next to null

        return newHead; // Return new head
    }

    // Utility method to print linked list
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.print("Original List: ");
        printList(head);

        // Iterative Reverse
        head = reverseListIterative(head);
        System.out.print("Reversed List (Iterative): ");
        printList(head);

        // Reverse back using Recursive method
        head = reverseListRecursive(head);
        System.out.print("Reversed List (Recursive): ");
        printList(head);
    }
}

class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class main {
    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode temp = head;
        int count = 0;

        // Count k nodes
        while (temp != null && count < k) {
            temp = temp.next;
            count++;
        }

        if (count == k) {
            ListNode prev = null, curr = head, next = null;
            for (int i = 0; i < k; i++) {
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

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.print("Original List: ");
        printList(head);

        int k = 2;
        head = reverseKGroup(head, k);

        System.out.print("List after reversing in k-groups: ");
        printList(head);
    }
}

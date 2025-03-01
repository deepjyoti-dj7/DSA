class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class main {
    public static ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // Find the length of the linked list
        int length = 1;
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        // Compute effective rotations
        k = k % length;
        if (k == 0) return head;

        // Find the new head position (length - k)
        ListNode cur = head;
        for (int i = 1; i < length - k; i++) {
            cur = cur.next;
        }

        // Break the list and reconnect
        ListNode newHead = cur.next;
        cur.next = null;
        tail.next = head;
        
        return newHead;
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
        head = rotateRight(head, k);
        
        System.out.print("List after rotating by " + k + ": ");
        printList(head);
    }
}

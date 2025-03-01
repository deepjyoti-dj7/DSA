class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class main {
    public static ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;

        while (cur != null) {
            while (cur.next != null && cur.val == cur.next.val)
                cur.next = cur.next.next;  // Skip duplicate node
            
            cur = cur.next; // Move forward
        }

        return head;
    }

    // Utility function to print a linked list
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(1);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(3);
        head.next.next.next.next = new ListNode(3);

        System.out.print("Original List: ");
        printList(head);

        head = deleteDuplicates(head);
        
        System.out.print("List after removing duplicates: ");
        printList(head);
    }
}

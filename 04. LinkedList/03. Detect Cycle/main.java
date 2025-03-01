class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class main {
    public static boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) return true; // Cycle detected
        }

        return false; // No cycle
    }

    // Helper method to create a cycle
    public static void createCycle(ListNode head, int pos) {
        if (pos == -1) return;
        ListNode temp = head, cycleNode = null;
        int index = 0;

        while (temp.next != null) {
            if (index == pos) cycleNode = temp;
            temp = temp.next;
            index++;
        }
        temp.next = cycleNode; // Create cycle
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(3);
        head.next = new ListNode(2);
        head.next.next = new ListNode(0);
        head.next.next.next = new ListNode(-4);

        createCycle(head, 1); // Create cycle at position 1

        System.out.println(hasCycle(head) ? "Cycle detected" : "No cycle");
    }
}

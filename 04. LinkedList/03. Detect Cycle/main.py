class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def hasCycle(head):
    slow, fast = head, head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True  # Cycle detected

    return False  # No cycle

# Helper function to create a cycle
def createCycle(head, pos):
    if pos == -1:
        return
    temp, cycleNode = head, None
    index = 0

    while temp.next:
        if index == pos:
            cycleNode = temp
        temp = temp.next
        index += 1
    temp.next = cycleNode  # Create cycle

# Main function
def main():
    head = ListNode(3)
    head.next = ListNode(2)
    head.next.next = ListNode(0)
    head.next.next.next = ListNode(-4)

    createCycle(head, 1)  # Cycle at position 1

    print("Cycle detected" if hasCycle(head) else "No cycle")

# Run main function
main()

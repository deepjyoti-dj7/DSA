class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def rotateRight(head, k):
    if not head or not head.next or k == 0:
        return head

    # Find the length of the linked list
    length = 1
    tail = head
    while tail.next:
        tail = tail.next
        length += 1

    # Compute effective rotations
    k = k % length
    if k == 0:
        return head

    # Find the new head position (length - k)
    cur = head
    for _ in range(1, length - k):
        cur = cur.next

    # Break the list and reconnect
    newHead = cur.next
    cur.next = None
    tail.next = head

    return newHead

# Utility function to print a linked list
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("NULL")

# Main function
def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print("Original List:")
    printList(head)

    k = 2
    head = rotateRight(head, k)

    print(f"List after rotating by {k}:")
    printList(head)

# Run main function
main()

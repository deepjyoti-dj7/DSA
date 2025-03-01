class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def swapPairs(head):
    if not head or not head.next:
        return head

    newHead = head.next
    prev = None

    while head and head.next:
        first = head
        second = head.next

        first.next = second.next
        second.next = first

        if prev:
            prev.next = second
        prev = first
        head = first.next

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

    print("Original List:")
    printList(head)

    head = swapPairs(head)

    print("List after swapping pairs:")
    printList(head)

# Run main function
if __name__ == "__main__":
    main()

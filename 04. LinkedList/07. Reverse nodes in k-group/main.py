class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def reverseKGroup(head, k):
    temp = head
    count = 0

    # Count k nodes
    while temp and count < k:
        temp = temp.next
        count += 1

    if count == k:
        prev, curr, next = None, head, None
        for _ in range(k):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        # Recursively process the remaining nodes
        head.next = reverseKGroup(next, k)
        return prev

    return head  # If fewer than k nodes remain, return the head as is

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
    head = reverseKGroup(head, k)

    print("List after reversing in k-groups:")
    printList(head)

# Run main function
if __name__ == "__main__":
    main()

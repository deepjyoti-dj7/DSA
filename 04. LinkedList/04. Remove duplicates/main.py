class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def deleteDuplicates(head):
    cur = head

    while cur:
        while cur.next and cur.val == cur.next.val:
            cur.next = cur.next.next  # Skip duplicate node
        
        cur = cur.next  # Move forward
            
    return head

# Utility function to print a linked list
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("NULL")

# Main function
def main():
    head = ListNode(1)
    head.next = ListNode(1)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(3)

    print("Original List:")
    printList(head)

    head = deleteDuplicates(head)

    print("List after removing duplicates:")
    printList(head)

# Run main function
if __name__ == "__main__":
    main()

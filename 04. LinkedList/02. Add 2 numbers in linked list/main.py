class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1, l2):
    dummy = ListNode(0)
    current = dummy
    carry = 0

    while l1 or l2 or carry:
        sum_val = carry
        if l1: sum_val += l1.val; l1 = l1.next
        if l2: sum_val += l2.val; l2 = l2.next

        carry = sum_val // 10
        current.next = ListNode(sum_val % 10)
        current = current.next

    return dummy.next

# Helper function to print linked list
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("NULL")

# Main function
def main():
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))

    result = addTwoNumbers(l1, l2)
    printList(result)

# Run main function
if __name__ == "__main__":
    main()

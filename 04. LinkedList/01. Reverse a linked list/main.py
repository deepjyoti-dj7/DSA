class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Iterative method
def reverse_list_iterative(head):
    prev = None
    current = head

    while current:
        next_node = current.next  # Store next node
        current.next = prev  # Reverse link
        prev = current  # Move prev forward
        current = next_node  # Move current forward

    return prev  # New head

# Recursive method
def reverse_list_recursive(head):
    if not head or not head.next:
        return head  # Base case: return last node as new head

    new_head = reverse_list_recursive(head.next)
    head.next.next = head  # Reverse link
    head.next = None  # Set current node's next to None

    return new_head  # Return new head

# Utility function to print linked list
def print_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("NULL")

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print("Original List:")
    print_list(head)

    # Iterative Reverse
    head = reverse_list_iterative(head)
    print("Reversed List (Iterative):")
    print_list(head)

    # Reverse back using Recursive method
    head = reverse_list_recursive(head)
    print("Reversed List (Recursive):")
    print_list(head)

if __name__ == "__main__":
    main()
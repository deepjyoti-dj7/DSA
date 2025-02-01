# Iterative Binary Search
def binary_search_iterative(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2  # Prevents overflow

        if arr[mid] == target:
            return mid  # Target found
        elif arr[mid] < target:
            left = mid + 1  # Search right half
        else:
            right = mid - 1  # Search left half

    return -1  # Target not found


# Recursive Binary Search
def binary_search_recursive(arr, left, right, target):
    if left > right:
        return -1  # Base case: target not found

    mid = left + (right - left) // 2  # Prevents overflow

    if arr[mid] == target:
        return mid  # Target found
    elif arr[mid] < target:
        return binary_search_recursive(arr, mid + 1, right, target)  # Search right half
    else:
        return binary_search_recursive(arr, left, mid - 1, target)  # Search left half


def main():
    arr = [2, 3, 4, 10, 40]
    target = 10

    # Iterative Binary Search
    iterative_result = binary_search_iterative(arr, target)
    print(f"Iterative: Element found at index {iterative_result}" if iterative_result != -1 else "Iterative: Element not found")

    # Recursive Binary Search
    recursive_result = binary_search_recursive(arr, 0, len(arr) - 1, target)
    print(f"Recursive: Element found at index {recursive_result}" if recursive_result != -1 else "Recursive: Element not found")

main()
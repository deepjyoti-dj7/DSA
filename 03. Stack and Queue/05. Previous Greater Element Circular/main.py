def previous_greater_element_circular(nums):
    n = len(nums)
    result = [-1] * n
    stack = []

    # Traverse twice in reverse order to simulate circular array
    for i in range(2 * n - 1, -1, -1):
        while stack and stack[-1] <= nums[i % n]:
            stack.pop()
        if i < n:
            if stack:
                result[i] = stack[-1]
            stack.append(nums[i])

    return result

# Main function
def main():
    nums = [4, 5, 2, 10, 8]
    result = previous_greater_element_circular(nums)

    print("Previous Greater Elements (Circular):")
    print(result)

main()
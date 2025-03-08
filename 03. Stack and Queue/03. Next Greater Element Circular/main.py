def next_greater_element_circular(nums):
    n = len(nums)
    result = [-1] * n
    stack = []

    for i in range(2 * n):
        while stack and nums[stack[-1]] < nums[i % n]:
            result[stack.pop()] = nums[i % n]
        if i < n:
            stack.append(i)

    return result

# Main function
if __name__ == "__main__":
    nums = [4, 5, 2, 10, 8]
    result = next_greater_element_circular(nums)

    print("Next Greater Elements (Circular):")
    print(result)

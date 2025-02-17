def next_greater_element(nums):
    stack = []
    result = [-1] * len(nums)

    for i in range(len(nums)):
        while stack and nums[stack[-1]] < nums[i]:
            result[stack.pop()] = nums[i]
        stack.append(i)

    return result

# Main function
def main():
    nums = [4, 5, 2, 10, 8]
    result = next_greater_element(nums)

    print("Next Greater Elements:")
    print(result)

# Run the main function
if __name__ == "__main__":
    main()

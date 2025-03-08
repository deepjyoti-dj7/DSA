def previous_greater_element(nums):
    stack = []
    result = [-1] * len(nums)

    for i in range(len(nums)):
        while stack and stack[-1] <= nums[i]:
            stack.pop()
        if stack:
            result[i] = stack[-1]
        stack.append(nums[i])

    return result

def main():
    nums = [4, 5, 2, 10, 8]
    result = previous_greater_element(nums)

    print("Previous Greater Elements:")
    print(" ".join(map(str, result)))

main()
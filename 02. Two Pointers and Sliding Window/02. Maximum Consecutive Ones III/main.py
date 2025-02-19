def longestOnes(nums, k):
    left = maxLength = zeroCount = 0

    for right in range(len(nums)):
        if nums[right] == 0:
            zeroCount += 1

        while zeroCount > k:
            if nums[left] == 0:
                zeroCount -= 1
            left += 1

        maxLength = max(maxLength, right - left + 1)

    return maxLength

# Main function
def main():
    nums = [1, 1, 0, 0, 1, 1, 1, 0, 1, 1]
    k = 2

    print(f"Maximum consecutive ones (with at most {k} flips):", longestOnes(nums, k))

# Run main function
if __name__ == "__main__":
    main()

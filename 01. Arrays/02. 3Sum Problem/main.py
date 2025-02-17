def three_sum(nums):
    nums.sort()  # Sort the array
    result = []

    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicates
            continue

        left, right = i + 1, len(nums) - 1
        while left < right:
            total = nums[i] + nums[left] + nums[right]

            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left + 1]:  # Skip duplicates
                    left += 1
                while left < right and nums[right] == nums[right - 1]:  # Skip duplicates
                    right -= 1
                left += 1
                right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1

    return result

# Main function
def main():
    nums = [-1, 0, 1, 2, -1, -4]
    result = three_sum(nums)

    print("Triplets that sum to zero:")
    print(result)

# Run the main function
if __name__ == "__main__":
    main()

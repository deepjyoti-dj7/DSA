def search(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return True

        # Handling duplicates
        if nums[left] == nums[mid] == nums[right]:
            left += 1
            right -= 1
            continue

        # Left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        # Right half is sorted
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

    return False

# Main function
def main():
    nums = [2, 5, 6, 0, 0, 1, 2]
    target = 0
    print("Target found:", "Yes" if search(nums, target) else "No")

# Run main function
if __name__ == "__main__":
    main()

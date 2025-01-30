def generateSubsets(index, nums, current, result):
    if index == len(nums):
        result.append(current[:])  # Store a copy of current subset
        return

    # Exclude the current element
    generateSubsets(index + 1, nums, current, result)

    # Include the current element
    current.append(nums[index])
    generateSubsets(index + 1, nums, current, result)
    current.pop()  # Backtrack

def subsets(nums):
    result = []
    generateSubsets(0, nums, [], result)
    return result

def main():
    nums = [1, 2, 3]
    print("Subsets using Backtracking:")
    print(subsets(nums))

if __name__ == "__main__":
    main()

def backtrack(nums, used, current, result):
    if len(current) == len(nums):
        result.append(current[:])
        return
    
    for i in range(len(nums)):
        if used[i]:
            continue
        
        used[i] = True
        current.append(nums[i])
        backtrack(nums, used, current, result)
        current.pop()
        used[i] = False

def permute(nums):
    result = []
    backtrack(nums, [False] * len(nums), [], result)
    return result

def main():
    nums = [1, 2, 3]
    print("Permutations:", permute(nums))

# Run the main function
if __name__ == "__main__":
    main()

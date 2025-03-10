def backtrack(candidates, target, start, current, result):
    if target == 0:
        result.append(current[:])
        return

    for i in range(start, len(candidates)):
        if i > start and candidates[i] == candidates[i - 1]:  # Skip duplicates
            continue
        if candidates[i] > target:  # No need to proceed
            break

        current.append(candidates[i])
        backtrack(candidates, target - candidates[i], i + 1, current, result)
        current.pop()  # Backtrack

def combinationSum2(candidates, target):
    result = []
    candidates.sort()  # Sort to handle duplicates
    backtrack(candidates, target, 0, [], result)
    return result

def main():
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    print("Combinations:", combinationSum2(candidates, target))

if __name__ == "__main__":
    main()

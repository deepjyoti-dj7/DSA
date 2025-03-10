def backtrack(start, n, k, current, result):
    if len(current) == k:
        result.append(list(current))
        return

    for i in range(start, n + 1):
        current.append(i)
        backtrack(i + 1, n, k, current, result)
        current.pop()  # Backtrack

def combine(n, k):
    result = []
    backtrack(1, n, k, [], result)
    return result

# Main function
def main():
    n, k = 4, 2
    result = combine(n, k)

    print("Combinations:")
    print(result)

main()

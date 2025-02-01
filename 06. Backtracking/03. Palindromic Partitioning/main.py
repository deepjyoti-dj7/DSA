# Function to check if a substring is a palindrome
def is_palindrome(s, start, end):
    while start < end:
        if s[start] != s[end]:
            return False
        start += 1
        end -= 1
    return True

# Backtracking function to generate partitions
def backtrack(start, s, current, result):
    if start == len(s):
        result.append(list(current))
        return
    
    for end in range(start, len(s)):
        if is_palindrome(s, start, end):
            current.append(s[start:end + 1])  # Take substring
            backtrack(end + 1, s, current, result)
            current.pop()  # Backtrack

# Function to generate all palindromic partitions
def partition(s):
    result = []
    backtrack(0, s, [], result)
    return result

# Utility function to print partitions
def print_partitions(partitions):
    print("[")
    for partition in partitions:
        print("  ", partition)
    print("]")

# Main function
def main():
    s = "aab"
    print(f'Palindromic Partitions of "{s}":')
    print_partitions(partition(s))

main()

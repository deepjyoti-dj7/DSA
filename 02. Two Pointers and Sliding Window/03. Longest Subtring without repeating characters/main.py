def brute_force(s):
    def all_unique(sub):
        return len(set(sub)) == len(sub)

    max_length = 0
    for i in range(len(s)):
        for j in range(i, len(s)):
            if all_unique(s[i:j+1]):
                max_length = max(max_length, j - i + 1)
    return max_length

def improved_brute_force(s):
    max_length = 0
    for i in range(len(s)):
        seen = set()
        for j in range(i, len(s)):
            if s[j] in seen:
                break
            seen.add(s[j])
            max_length = max(max_length, j - i + 1)
    return max_length

def sliding_window(s):
    last_seen = {}
    left = max_length = 0
    for right, char in enumerate(s):
        if char in last_seen:
            left = max(left, last_seen[char] + 1)
        last_seen[char] = right
        max_length = max(max_length, right - left + 1)
    return max_length

def sliding_window_set(s):
    seen = set()
    left = max_length = 0
    for right in range(len(s)):
        while s[right] in seen:
            seen.remove(s[left])
            left += 1
        seen.add(s[right])
        max_length = max(max_length, right - left + 1)
    return max_length

def main():
    s = input("Enter a string: ")
    print("Brute Force:", brute_force(s))
    print("Improved Brute Force:", improved_brute_force(s))
    print("Sliding Window (Hash Map):", sliding_window(s))
    print("Sliding Window (Hash Set):", sliding_window_set(s))

main()

# Python implementation of Longest Common Substring

def LCS_Iterative(s1, s2):
    res = 0
    n, m = len(s1), len(s2)
    for i in range(n):
        for j in range(m):
            curr = 0
            while i + curr < n and j + curr < m and s1[i + curr] == s2[j + curr]:
                curr += 1
            res = max(res, curr)
    return res

def LCS_Solve(s1, s2, n, m):
    if n == 0 or m == 0 or s1[n - 1] != s2[m - 1]:
        return 0
    return 1 + LCS_Solve(s1, s2, n - 1, m - 1)

def LCS_Recursion(s1, s2):
    res = 0
    for i in range(1, len(s1) + 1):
        for j in range(1, len(s2) + 1):
            res = max(res, LCS_Solve(s1, s2, i, j))
    return res

def LCS_Tabulation(s1, s2):
    res = 0
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
                res = max(res, dp[i][j])
            else:
                dp[i][j] = 0
    return res

def LCS_Tabulation_SpaceOptimized(s1, s2):
    res = 0
    n, m = len(s1), len(s2)
    prev = [0] * (m + 1)
    cur = [0] * (m + 1)

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                cur[j] = prev[j - 1] + 1
                res = max(res, cur[j])
            else:
                cur[j] = 0
        prev = cur[:]
    return res

def LCS_Tabulation_Print(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    max_len = 0
    end_index = -1

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
                if dp[i][j] > max_len:
                    max_len = dp[i][j]
                    end_index = i - 1
            else:
                dp[i][j] = 0

    lcs = ""
    if max_len > 0:
        lcs = s1[end_index - max_len + 1:end_index + 1]

    print(f"Longest Common Substring: {lcs} || and length is: {max_len}")

    return lcs

def LCS_Tabulation_SpaceOptimized_Print(s1, s2):
    n, m = len(s1), len(s2)
    prev = [0] * (m + 1)
    cur = [0] * (m + 1)
    max_len = 0
    end_index = -1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                cur[j] = prev[j - 1] + 1
                if cur[j] > max_len:
                    max_len = cur[j]
                    end_index = i - 1
            else:
                cur[j] = 0
        prev = cur[:]

    lcs = ""
    if max_len > 0:
        lcs = s1[end_index - max_len + 1:end_index + 1]

    print(f"Longest Common Substring: {lcs} || and length is: {max_len}")

    return lcs

# Main function to test the implementation
def main():
    s1 = "geeksforgeeks"
    s2 = "practicewritegeekscourses"

    print("Longest Common Substring Iterative:", LCS_Iterative(s1, s2))
    print("Longest Common Substring Recursion:", LCS_Recursion(s1, s2))
    print("Longest Common Substring Tabulation:", LCS_Tabulation(s1, s2))
    print("Longest Common Substring Tabulation_SpaceOptimized:", LCS_Tabulation_SpaceOptimized(s1, s2))

    LCS_Tabulation_Print(s1, s2)
    LCS_Tabulation_SpaceOptimized_Print(s1, s2)

if __name__ == "__main__":
    main()

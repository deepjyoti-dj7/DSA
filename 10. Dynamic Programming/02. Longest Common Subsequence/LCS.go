package main

import (
	"fmt"
)

// 1. Brute Force Recursive
func LCS(s1, s2 string, i, j int) int {
	if i < 0 || j < 0 {
		return 0
	}
	if s1[i] == s2[j] {
		return 1 + LCS(s1, s2, i-1, j-1)
	}
	return max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1))
}

// 2. Memoization
func LCSMemo(s1, s2 string, i, j int, dp [][]int) int {
	if i < 0 || j < 0 {
		return 0
	}
	if dp[i][j] != -1 {
		return dp[i][j]
	}
	if s1[i] == s2[j] {
		dp[i][j] = 1 + LCSMemo(s1, s2, i-1, j-1, dp)
	} else {
		dp[i][j] = max(LCSMemo(s1, s2, i-1, j, dp), LCSMemo(s1, s2, i, j-1, dp))
	}
	return dp[i][j]
}

// 3. Tabulation
func LCSTab(s1, s2 string) int {
	n, m := len(s1), len(s2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return dp[n][m]
}

// 4. Space Optimized
func LCSSpaceOptimized(s1, s2 string) int {
	n, m := len(s1), len(s2)
	prev := make([]int, m+1)
	cur := make([]int, m+1)

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				cur[j] = 1 + prev[j-1]
			} else {
				cur[j] = max(prev[j], cur[j-1])
			}
		}
		copy(prev, cur)
	}
	return prev[m]
}

// 5. LCS Print
func LCSPrint(s1, s2 string) string {
	n, m := len(s1), len(s2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	i, j := n, m
	lcs := []byte{}

	for i > 0 && j > 0 {
		if s1[i-1] == s2[j-1] {
			lcs = append(lcs, s1[i-1])
			i--
			j--
		} else if dp[i-1][j] > dp[i][j-1] {
			i--
		} else {
			j--
		}
	}

	// reverse lcs
	for i := 0; i < len(lcs)/2; i++ {
		lcs[i], lcs[len(lcs)-1-i] = lcs[len(lcs)-1-i], lcs[i]
	}
	return string(lcs)
}

// Utility
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// MAIN
func main() {
	s1 := "abcde"
	s2 := "ace"

	fmt.Println("Brute Force:", LCS(s1, s2, len(s1)-1, len(s2)-1))

	dp := make([][]int, len(s1))
	for i := range dp {
		dp[i] = make([]int, len(s2))
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	fmt.Println("Memoization:", LCSMemo(s1, s2, len(s1)-1, len(s2)-1, dp))
	fmt.Println("Tabulation:", LCSTab(s1, s2))
	fmt.Println("Space Optimized:", LCSSpaceOptimized(s1, s2))
	fmt.Println("LCS String:", LCSPrint(s1, s2))
}

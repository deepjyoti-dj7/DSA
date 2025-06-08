package main

import (
	"fmt"
	"math"
)

// 1. Brute Force (Recursive)
func editDistanceBrute(s1, s2 string, i, j int) int {
	if i == 0 {
		return j
	}
	if j == 0 {
		return i
	}
	if s1[i-1] == s2[j-1] {
		return editDistanceBrute(s1, s2, i-1, j-1)
	}
	return 1 + min(
		editDistanceBrute(s1, s2, i-1, j),   // delete
		editDistanceBrute(s1, s2, i, j-1),   // insert
		editDistanceBrute(s1, s2, i-1, j-1), // replace
	)
}

// 2. Memoization (Top-down DP)
func editDistanceMemo(s1, s2 string, i, j int, dp [][]int) int {
	if i == 0 {
		return j
	}
	if j == 0 {
		return i
	}
	if dp[i][j] != -1 {
		return dp[i][j]
	}
	if s1[i-1] == s2[j-1] {
		dp[i][j] = editDistanceMemo(s1, s2, i-1, j-1, dp)
	} else {
		dp[i][j] = 1 + min(
			editDistanceMemo(s1, s2, i-1, j, dp),
			editDistanceMemo(s1, s2, i, j-1, dp),
			editDistanceMemo(s1, s2, i-1, j-1, dp),
		)
	}
	return dp[i][j]
}

// 3. Tabulation (Bottom-up DP)
func editDistanceTab(s1, s2 string) int {
	n, m := len(s1), len(s2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	for i := 0; i <= n; i++ {
		dp[i][0] = i
	}
	for j := 0; j <= m; j++ {
		dp[0][j] = j
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
			}
		}
	}

	return dp[n][m]
}

// 4. Space Optimized DP (Only 2 rows)
func editDistanceSpaceOpt(s1, s2 string) int {
	n, m := len(s1), len(s2)
	prev := make([]int, m+1)
	curr := make([]int, m+1)

	for j := 0; j <= m; j++ {
		prev[j] = j
	}

	for i := 1; i <= n; i++ {
		curr[0] = i
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				curr[j] = prev[j-1]
			} else {
				curr[j] = 1 + min(prev[j], curr[j-1], prev[j-1])
			}
		}
		prev, curr = curr, prev
	}

	return prev[m]
}

// Utility function to get minimum of 3 ints
func min(a, b, c int) int {
	return int(math.Min(float64(a), math.Min(float64(b), float64(c))))
}

func main() {
	s1 := "horse"
	s2 := "ros"

	fmt.Println("Brute Force:", editDistanceBrute(s1, s2, len(s1), len(s2)))

	dp := make([][]int, len(s1)+1)
	for i := range dp {
		dp[i] = make([]int, len(s2)+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	fmt.Println("Memoization:", editDistanceMemo(s1, s2, len(s1), len(s2), dp))

	fmt.Println("Tabulation:", editDistanceTab(s1, s2))
	fmt.Println("Space Optimized:", editDistanceSpaceOpt(s1, s2))
}

package main

import (
	"fmt"
)

// 1. Iterative Brute Force
func LCSIterative(s1, s2 string) int {
	res := 0
	n, m := len(s1), len(s2)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			curr := 0
			for (i+curr) < n && (j+curr) < m && s1[i+curr] == s2[j+curr] {
				curr++
			}
			if curr > res {
				res = curr
			}
		}
	}
	return res
}

// Helper for Recursion
func LCSSolve(s1, s2 string, n, m int) int {
	if n == 0 || m == 0 || s1[n-1] != s2[m-1] {
		return 0
	}
	return 1 + LCSSolve(s1, s2, n-1, m-1)
}

// 2. Recursive
func LCSRecursion(s1, s2 string) int {
	res := 0
	for i := 1; i <= len(s1); i++ {
		for j := 1; j <= len(s2); j++ {
			temp := LCSSolve(s1, s2, i, j)
			if temp > res {
				res = temp
			}
		}
	}
	return res
}

// 3. Tabulation
func LCSTabulation(s1, s2 string) int {
	res := 0
	n, m := len(s1), len(s2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
				if dp[i][j] > res {
					res = dp[i][j]
				}
			}
		}
	}
	return res
}

// 4. Space Optimized
func LCSTabulationSpaceOptimized(s1, s2 string) int {
	n, m := len(s1), len(s2)
	prev := make([]int, m+1)
	cur := make([]int, m+1)
	res := 0

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				cur[j] = prev[j-1] + 1
				if cur[j] > res {
					res = cur[j]
				}
			} else {
				cur[j] = 0
			}
		}
		copy(prev, cur)
	}
	return res
}

// 5. Tabulation with Print
func LCSTabulationPrint(s1, s2 string) string {
	n, m := len(s1), len(s2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	maxLen, endIndex := 0, -1
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
				if dp[i][j] > maxLen {
					maxLen = dp[i][j]
					endIndex = i - 1
				}
			}
		}
	}

	if maxLen > 0 {
		return s1[endIndex-maxLen+1 : endIndex+1]
	}
	return ""
}

// 6. Space Optimized Print
func LCSTabulationSpaceOptimizedPrint(s1, s2 string) string {
	n, m := len(s1), len(s2)
	prev := make([]int, m+1)
	cur := make([]int, m+1)
	maxLen, endIndex := 0, -1

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				cur[j] = prev[j-1] + 1
				if cur[j] > maxLen {
					maxLen = cur[j]
					endIndex = i - 1
				}
			} else {
				cur[j] = 0
			}
		}
		copy(prev, cur)
	}

	if maxLen > 0 {
		return s1[endIndex-maxLen+1 : endIndex+1]
	}
	return ""
}

// Main Function
func main() {
	s1 := "geeksforgeeks"
	s2 := "practicewritegeekscourses"

	fmt.Println("LCS Iterative:", LCSIterative(s1, s2))
	fmt.Println("LCS Recursion:", LCSRecursion(s1, s2))
	fmt.Println("LCS Tabulation:", LCSTabulation(s1, s2))
	fmt.Println("LCS Tabulation Space Optimized:", LCSTabulationSpaceOptimized(s1, s2))

	fmt.Println("LCS Tabulation Print:", LCSTabulationPrint(s1, s2))
	fmt.Println("LCS Tabulation Space Optimized Print:", LCSTabulationSpaceOptimizedPrint(s1, s2))
}

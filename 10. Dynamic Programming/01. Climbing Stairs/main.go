package main

import "fmt"

// 1. Brute Force
func climbBrute(n int) int {
	if n <= 1 {
		return 1
	}
	return climbBrute(n-1) + climbBrute(n-2)
}

// 2. Memoization
func climbMemo(n int, memo []int) int {
	if n <= 1 {
		return 1
	}
	if memo[n] != -1 {
		return memo[n]
	}
	memo[n] = climbMemo(n-1, memo) + climbMemo(n-2, memo)
	return memo[n]
}

// 3. Tabulation
func climbTab(n int) int {
	if n <= 1 {
		return 1
	}
	dp := make([]int, n+1)
	dp[0], dp[1] = 1, 1
	for i := 2; i <= n; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return dp[n]
}

// 4. Space Optimized
func climbOpt(n int) int {
	if n <= 1 {
		return 1
	}
	a, b := 1, 1
	for i := 2; i <= n; i++ {
		a, b = b, a+b
	}
	return b
}

func main() {
	n := 5

	memo := make([]int, n+1)
	for i := range memo {
		memo[i] = -1
	}

	fmt.Println("Brute:", climbBrute(n))
	fmt.Println("Memo:", climbMemo(n, memo))
	fmt.Println("Tabulation:", climbTab(n))
	fmt.Println("Optimized:", climbOpt(n))
}

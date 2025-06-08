package main

import (
	"fmt"
)

// 1. Brute Force (Recursive)
func bruteForce(prices []int, i int, holding bool) int {
	if i >= len(prices) {
		return 0
	}
	if holding {
		return max(
			prices[i]+bruteForce(prices, i+2, false), // Sell + cooldown
			bruteForce(prices, i+1, true),           // Hold
		)
	} else {
		return max(
			-prices[i]+bruteForce(prices, i+1, true), // Buy
			bruteForce(prices, i+1, false),          // Skip
		)
	}
}

func maxProfitBruteForce(prices []int) int {
	return bruteForce(prices, 0, false)
}

// 2. Memoization
func memoizedDFS(prices []int, i int, holding int, memo [][]int) int {
	if i >= len(prices) {
		return 0
	}
	if memo[i][holding] != -1 {
		return memo[i][holding]
	}

	if holding == 1 {
		memo[i][holding] = max(
			prices[i]+memoizedDFS(prices, i+2, 0, memo), // Sell + cooldown
			memoizedDFS(prices, i+1, 1, memo),           // Hold
		)
	} else {
		memo[i][holding] = max(
			-prices[i]+memoizedDFS(prices, i+1, 1, memo), // Buy
			memoizedDFS(prices, i+1, 0, memo),            // Skip
		)
	}
	return memo[i][holding]
}

func maxProfitMemo(prices []int) int {
	n := len(prices)
	memo := make([][]int, n)
	for i := range memo {
		memo[i] = []int{-1, -1}
	}
	return memoizedDFS(prices, 0, 0, memo)
}

// 3. Bottom-Up DP
func maxProfitDP(prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}

	dp := make([][]int, n+2)
	for i := range dp {
		dp[i] = []int{0, 0}
	}

	for i := n - 1; i >= 0; i-- {
		dp[i][1] = max(prices[i]+dp[i+2][0], dp[i+1][1])
		dp[i][0] = max(-prices[i]+dp[i+1][1], dp[i+1][0])
	}

	return dp[0][0]
}

// 4. Optimized DP with O(1) Space
func maxProfitOptimizedDP(prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}

	aheadNotHolding, aheadHolding, aheadCooldown := 0, 0, 0

	for i := n - 1; i >= 0; i-- {
		tempNotHolding := max(-prices[i]+aheadHolding, aheadNotHolding)
		tempHolding := max(prices[i]+aheadCooldown, aheadHolding)

		aheadCooldown = aheadNotHolding
		aheadNotHolding = tempNotHolding
		aheadHolding = tempHolding
	}
	return aheadNotHolding
}

// Utility function
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function to test all methods
func main() {
	prices := []int{1, 2, 3, 0, 2}

	fmt.Println("Brute Force:", maxProfitBruteForce(prices))
	fmt.Println("Memoization:", maxProfitMemo(prices))
	fmt.Println("Bottom-Up DP:", maxProfitDP(prices))
	fmt.Println("Optimized DP:", maxProfitOptimizedDP(prices))
}

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
		return max(prices[i]+bruteForce(prices, i+1, false),
			bruteForce(prices, i+1, true))
	} else {
		return max(-prices[i]+bruteForce(prices, i+1, true),
			bruteForce(prices, i+1, false))
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
		memo[i][holding] = max(prices[i]+memoizedDFS(prices, i+1, 0, memo),
			memoizedDFS(prices, i+1, 1, memo))
	} else {
		memo[i][holding] = max(-prices[i]+memoizedDFS(prices, i+1, 1, memo),
			memoizedDFS(prices, i+1, 0, memo))
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
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	for i := n - 1; i >= 0; i-- {
		dp[i][1] = max(prices[i]+dp[i+1][0], dp[i+1][1]) // holding
		dp[i][0] = max(-prices[i]+dp[i+1][1], dp[i+1][0]) // not holding
	}
	return dp[0][0]
}

// 4. Optimized DP with O(1) space
func maxProfitOptimizedDP(prices []int) int {
	aheadNotHolding := 0
	aheadHolding := 0
	for i := len(prices) - 1; i >= 0; i-- {
		tempNotHolding := max(-prices[i]+aheadHolding, aheadNotHolding)
		tempHolding := max(prices[i]+aheadNotHolding, aheadHolding)
		aheadNotHolding = tempNotHolding
		aheadHolding = tempHolding
	}
	return aheadNotHolding
}

// 5. Greedy
func maxProfitGreedy(prices []int) int {
	profit := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] > prices[i-1] {
			profit += prices[i] - prices[i-1]
		}
	}
	return profit
}

// Helper max
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// --- MAIN ---
func main() {
	prices := []int{7, 1, 5, 3, 6, 4}

	fmt.Println("Brute Force:", maxProfitBruteForce(prices))
	fmt.Println("Memoization:", maxProfitMemo(prices))
	fmt.Println("Bottom-Up DP:", maxProfitDP(prices))
	fmt.Println("Optimized DP:", maxProfitOptimizedDP(prices))
	fmt.Println("Greedy Approach:", maxProfitGreedy(prices))
}

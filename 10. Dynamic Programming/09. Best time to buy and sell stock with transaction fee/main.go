package main

import (
	"fmt"
)

// 1. Brute Force (Recursive)
func bruteForce(prices []int, i int, holding bool, fee int) int {
	if i >= len(prices) {
		return 0
	}
	if holding {
		return max(
			prices[i]-fee+bruteForce(prices, i+1, false, fee), // Sell
			bruteForce(prices, i+1, true, fee),               // Hold
		)
	} else {
		return max(
			-prices[i]+bruteForce(prices, i+1, true, fee), // Buy
			bruteForce(prices, i+1, false, fee),           // Skip
		)
	}
}

func maxProfitBruteForce(prices []int, fee int) int {
	return bruteForce(prices, 0, false, fee)
}

// 2. Memoization
func memoizedDFS(prices []int, i int, holding int, fee int, memo [][]int) int {
	if i >= len(prices) {
		return 0
	}
	if memo[i][holding] != -1 {
		return memo[i][holding]
	}

	if holding == 1 {
		memo[i][holding] = max(
			prices[i]-fee+memoizedDFS(prices, i+1, 0, fee, memo), // Sell
			memoizedDFS(prices, i+1, 1, fee, memo),               // Hold
		)
	} else {
		memo[i][holding] = max(
			-prices[i]+memoizedDFS(prices, i+1, 1, fee, memo), // Buy
			memoizedDFS(prices, i+1, 0, fee, memo),            // Skip
		)
	}
	return memo[i][holding]
}

func maxProfitMemo(prices []int, fee int) int {
	n := len(prices)
	memo := make([][]int, n)
	for i := range memo {
		memo[i] = []int{-1, -1}
	}
	return memoizedDFS(prices, 0, 0, fee, memo)
}

// 3. Bottom-Up DP
func maxProfitDP(prices []int, fee int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = []int{0, 0}
	}
	for i := n - 1; i >= 0; i-- {
		dp[i][1] = max(prices[i]-fee+dp[i+1][0], dp[i+1][1])
		dp[i][0] = max(-prices[i]+dp[i+1][1], dp[i+1][0])
	}
	return dp[0][0]
}

// 4. Optimized DP
func maxProfitOptimizedDP(prices []int, fee int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	aheadNotHolding, aheadHolding := 0, 0
	for i := n - 1; i >= 0; i-- {
		tempNotHolding := max(-prices[i]+aheadHolding, aheadNotHolding)
		tempHolding := max(prices[i]-fee+aheadNotHolding, aheadHolding)
		aheadNotHolding = tempNotHolding
		aheadHolding = tempHolding
	}
	return aheadNotHolding
}

// 5. Greedy Approach
func maxProfitGreedy(prices []int, fee int) int {
	if len(prices) == 0 {
		return 0
	}
	profit := 0
	minPrice := prices[0]
	for i := 1; i < len(prices); i++ {
		if prices[i] < minPrice {
			minPrice = prices[i]
		}
		if prices[i] > minPrice+fee {
			profit += prices[i] - minPrice - fee
			minPrice = prices[i] - fee
		}
	}
	return profit
}

// Utility
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main
func main() {
	prices := []int{1, 3, 2, 8, 4, 9}
	fee := 2

	fmt.Println("Brute Force:", maxProfitBruteForce(prices, fee))
	fmt.Println("Memoization:", maxProfitMemo(prices, fee))
	fmt.Println("Bottom-Up DP:", maxProfitDP(prices, fee))
	fmt.Println("Optimized DP:", maxProfitOptimizedDP(prices, fee))
	fmt.Println("Greedy Approach:", maxProfitGreedy(prices, fee))
}

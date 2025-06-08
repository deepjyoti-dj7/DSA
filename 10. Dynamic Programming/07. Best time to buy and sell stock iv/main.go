package main

import (
	"fmt"
	"math"
)

// 1. Brute Force (Recursive)
func bruteForce(prices []int, i int, transactionsLeft int, holding bool) int {
	if i >= len(prices) || transactionsLeft == 0 {
		return 0
	}
	if holding {
		return max(
			prices[i]+bruteForce(prices, i+1, transactionsLeft-1, false),
			bruteForce(prices, i+1, transactionsLeft, true),
		)
	} else {
		return max(
			-prices[i]+bruteForce(prices, i+1, transactionsLeft, true),
			bruteForce(prices, i+1, transactionsLeft, false),
		)
	}
}

func maxProfitBruteForce(prices []int) int {
	return bruteForce(prices, 0, 2, false)
}

// 2. Memoization
func memoizedDFS(prices []int, i int, transactionsLeft int, holding int, memo [][][]int) int {
	if i >= len(prices) || transactionsLeft == 0 {
		return 0
	}
	if memo[i][transactionsLeft][holding] != -1 {
		return memo[i][transactionsLeft][holding]
	}
	if holding == 1 {
		memo[i][transactionsLeft][holding] = max(
			prices[i]+memoizedDFS(prices, i+1, transactionsLeft-1, 0, memo),
			memoizedDFS(prices, i+1, transactionsLeft, 1, memo),
		)
	} else {
		memo[i][transactionsLeft][holding] = max(
			-prices[i]+memoizedDFS(prices, i+1, transactionsLeft, 1, memo),
			memoizedDFS(prices, i+1, transactionsLeft, 0, memo),
		)
	}
	return memo[i][transactionsLeft][holding]
}

func maxProfitMemo(prices []int) int {
	n := len(prices)
	memo := make([][][]int, n)
	for i := range memo {
		memo[i] = make([][]int, 3)
		for j := range memo[i] {
			memo[i][j] = []int{-1, -1}
		}
	}
	return memoizedDFS(prices, 0, 2, 0, memo)
}

// 3. Bottom-Up DP
func maxProfitDP(prices []int) int {
	n := len(prices)
	dp := make([][][]int, n+1)
	for i := range dp {
		dp[i] = make([][]int, 3)
		for j := range dp[i] {
			dp[i][j] = make([]int, 2)
		}
	}

	for i := n - 1; i >= 0; i-- {
		for t := 1; t <= 2; t++ {
			dp[i][t][1] = max(prices[i]+dp[i+1][t-1][0], dp[i+1][t][1])
			dp[i][t][0] = max(-prices[i]+dp[i+1][t][1], dp[i+1][t][0])
		}
	}
	return dp[0][2][0]
}

// 4. Optimized DP (O(1) Space)
func maxProfitOptimizedDP(prices []int) int {
	buy1, sell1 := math.MinInt32, 0
	buy2, sell2 := math.MinInt32, 0

	for _, price := range prices {
		buy1 = max(buy1, -price)
		sell1 = max(sell1, buy1+price)
		buy2 = max(buy2, sell1-price)
		sell2 = max(sell2, buy2+price)
	}
	return sell2
}

// Utility function
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// --- Main ---
func main() {
	prices := []int{3, 3, 5, 0, 0, 3, 1, 4}

	fmt.Println("Brute Force:", maxProfitBruteForce(prices))
	fmt.Println("Memoization:", maxProfitMemo(prices))
	fmt.Println("Bottom-Up DP:", maxProfitDP(prices))
	fmt.Println("Optimized DP:", maxProfitOptimizedDP(prices))
}

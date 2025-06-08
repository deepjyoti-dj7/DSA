package main

import (
	"fmt"
	"sort"
)

// 1. Pure Recursion
func LIS(arr []int, ind, prev int) int {
	if ind == len(arr) {
		return 0
	}
	notTake := LIS(arr, ind+1, prev)
	take := 0
	if prev == -1 || arr[prev] < arr[ind] {
		take = 1 + LIS(arr, ind+1, ind)
	}
	return max(take, notTake)
}

// 2. Memoization
func LISMemoization(arr []int, ind, prev int, dp [][]int) int {
	if ind == len(arr) {
		return 0
	}
	if dp[ind][prev+1] != -1 {
		return dp[ind][prev+1]
	}
	notTake := LISMemoization(arr, ind+1, prev, dp)
	take := 0
	if prev == -1 || arr[prev] < arr[ind] {
		take = 1 + LISMemoization(arr, ind+1, ind, dp)
	}
	dp[ind][prev+1] = max(take, notTake)
	return dp[ind][prev+1]
}

// 3. Tabulation
func LISTabulation(arr []int, n int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for ind := n - 1; ind >= 0; ind-- {
		for prev := ind - 1; prev >= -1; prev-- {
			take := 0
			if prev == -1 || arr[prev] < arr[ind] {
				take = 1 + dp[ind+1][ind]
			}
			dp[ind][prev+1] = max(take, dp[ind+1][prev+1])
		}
	}
	return dp[0][0]
}

// 4. Space Optimization 1
func LISTabSpaceOpt1(arr []int, n int) int {
	cur := make([]int, n+1)
	next := make([]int, n+1)

	for ind := n - 1; ind >= 0; ind-- {
		for prev := ind - 1; prev >= -1; prev-- {
			take := 0
			if prev == -1 || arr[prev] < arr[ind] {
				take = 1 + next[ind]
			}
			cur[prev+1] = max(take, next[prev+1])
		}
		copy(next, cur)
	}
	return next[0]
}

// 5. Space Optimization 2 (Simplest Efficient DP)
func LISTabSpaceOpt2(arr []int, n int) int {
	dp := make([]int, n)
	for i := range dp {
		dp[i] = 1
	}
	maxi := 1

	for i := 0; i < n; i++ {
		for prev := 0; prev < i; prev++ {
			if arr[prev] < arr[i] {
				dp[i] = max(dp[i], 1+dp[prev])
			}
		}
		maxi = max(maxi, dp[i])
	}
	return maxi
}

// 6. Print the actual LIS
func LISPrint(arr []int, n int) int {
	dp := make([]int, n)
	hash := make([]int, n)
	for i := range dp {
		dp[i] = 1
		hash[i] = i
	}

	maxi, lastIndex := 1, 0

	for i := 0; i < n; i++ {
		for prev := 0; prev < i; prev++ {
			if arr[prev] < arr[i] && 1+dp[prev] > dp[i] {
				dp[i] = 1 + dp[prev]
				hash[i] = prev
			}
		}
		if dp[i] > maxi {
			maxi = dp[i]
			lastIndex = i
		}
	}

	// Reconstruct the sequence
	res := []int{}
	for lastIndex != hash[lastIndex] {
		res = append([]int{arr[lastIndex]}, res...)
		lastIndex = hash[lastIndex]
	}
	res = append([]int{arr[lastIndex]}, res...)

	fmt.Println("LIS is:", res)
	return maxi
}

// 7. Binary Search Method (Patience Sorting)
func LISBinarySearch(arr []int, n int) int {
	sub := []int{}
	for _, val := range arr {
		idx := sort.SearchInts(sub, val)
		if idx == len(sub) {
			sub = append(sub, val)
		} else {
			sub[idx] = val
		}
	}
	return len(sub)
}

// Utility max function
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// --- MAIN ---
func main() {
	arr := []int{1, 2, 3, 5, 6, 0, 1}
	n := len(arr)

	fmt.Println("Length of LIS using Recursion:", LIS(arr, 0, -1))

	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	fmt.Println("Length of LIS using Memoization:", LISMemoization(arr, 0, -1, dp))

	fmt.Println("Length of LIS using Tabulation:", LISTabulation(arr, n))

	fmt.Println("Length of LIS using Tabulation Space Optimized 1:", LISTabSpaceOpt1(arr, n))

	fmt.Println("Length of LIS using Tabulation Space Optimized 2:", LISTabSpaceOpt2(arr, n))

	fmt.Println("Length of LIS using LISPrint:", LISPrint(arr, n))

	fmt.Println("Length of LIS using Binary Search:", LISBinarySearch(arr, n))
}

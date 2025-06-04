package main

import (
	"fmt"
	"sort"
)

// Brute Force Approach: O(N^2) Time, O(1) Space
func twoSumBruteForce(nums []int, target int) []int {
	n := len(nums)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if nums[i]+nums[j] == target {
				return []int{nums[i], nums[j]} // Return values of the two numbers
			}
		}
	}
	return nil // No solution found
}

// Sorting + Two Pointers Approach: O(N log N) Time, O(N) Space (for sorting + indexing)
func twoSumTwoPointers(nums []int, target int) []int {
	type pair struct {
		value int
		index int
	}

	indexedNums := make([]pair, len(nums))
	for i, v := range nums {
		indexedNums[i] = pair{v, i}
	}

	sort.Slice(indexedNums, func(i, j int) bool {
		return indexedNums[i].value < indexedNums[j].value
	})

	left, right := 0, len(nums)-1
	for left < right {
		sum := indexedNums[left].value + indexedNums[right].value
		if sum == target {
			return []int{indexedNums[left].value, indexedNums[right].value} // Return values
		} else if sum < target {
			left++
		} else {
			right--
		}
	}
	return nil // No solution found
}

// Hashing (Optimal) Approach: O(N) Time, O(N) Space
func twoSumHashing(nums []int, target int) []int {
	numMap := make(map[int]int) // value -> index

	for _, num := range nums {
		complement := target - num
		if _, found := numMap[complement]; found {
			return []int{complement, num} // Return values
		}
		numMap[num] = 1
	}
	return nil // No solution found
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9

	result1 := twoSumBruteForce(nums, target)
	if result1 != nil {
		fmt.Printf("Brute Force: [%d, %d]\n", result1[0], result1[1])
	} else {
		fmt.Println("No solution found using Brute Force")
	}

	result2 := twoSumTwoPointers(nums, target)
	if result2 != nil {
		fmt.Printf("Two Pointers: [%d, %d]\n", result2[0], result2[1])
	} else {
		fmt.Println("No solution found using Two Pointers")
	}

	result3 := twoSumHashing(nums, target)
	if result3 != nil {
		fmt.Printf("Hashing: [%d, %d]\n", result3[0], result3[1])
	} else {
		fmt.Println("No solution found using Hashing")
	}
}

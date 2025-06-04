package main

import (
	"fmt"
	"sort"
)

// Brute Force O(N^3)
func threeSumBruteForce(nums []int) [][]int {
    uniqueTriplets := make(map[[3]int]bool)
    n := len(nums)

    for i := 0; i < n-2; i++ {
        for j := i + 1; j < n-1; j++ {
            for k := j + 1; k < n; k++ {
                if nums[i]+nums[j]+nums[k] == 0 {
                    triplet := [3]int{nums[i], nums[j], nums[k]}
                    sort.Ints(triplet[:])
                    uniqueTriplets[triplet] = true
                }
            }
        }
    }

    var result [][]int
    for triplet := range uniqueTriplets {
        result = append(result, []int{triplet[0], triplet[1], triplet[2]})
    }
    return result
}

// Optimized Two Pointers O(N^2)
func threeSumOptimized(nums []int) [][]int {
    sort.Ints(nums)
    var result [][]int

    for i := 0; i < len(nums)-2; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        left, right := i+1, len(nums)-1
        for left < right {
            sum := nums[i] + nums[left] + nums[right]
            if sum == 0 {
                result = append(result, []int{nums[i], nums[left], nums[right]})

                for left < right && nums[left] == nums[left+1] {
                    left++
                }
                for left < right && nums[right] == nums[right-1] {
                    right--
                }
                left++
                right--
            } else if sum < 0 {
                left++
            } else {
                right--
            }
        }
    }
    return result
}

func printTriplets(triplets [][]int) {
    for _, t := range triplets {
        fmt.Println(t)
    }
}

func main() {
    nums := []int{-1, 0, 1, 2, -1, -4}

    fmt.Println("Brute Force Approach results:")
    brute := threeSumBruteForce(nums)
    printTriplets(brute)

    fmt.Println("\nOptimized Two Pointers Approach results:")
    optimized := threeSumOptimized(nums)
    printTriplets(optimized)
}

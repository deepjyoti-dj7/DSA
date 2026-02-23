package main

import (
	"fmt"
	"math"
)

func bellmanFord(n, src int, edges [][]int) []int {
	dist := make([]int, n)

	// Initialize distances
	for i := 0; i < n; i++ {
		dist[i] = math.MaxInt
	}
	dist[src] = 0

	// Relax all edges (n-1) times
	for i := 0; i < n-1; i++ {
		for _, edge := range edges {
			u := edge[0]
			v := edge[1]
			weight := edge[2]

			if dist[u] != math.MaxInt && dist[u]+weight < dist[v] {
				dist[v] = dist[u] + weight
			}
		}
	}

	// Check for negative weight cycle
	for _, edge := range edges {
		u := edge[0]
		v := edge[1]
		weight := edge[2]

		if dist[u] != math.MaxInt && dist[u]+weight < dist[v] {
			fmt.Println("Negative weight cycle detected!")
			return []int{}
		}
	}

	return dist
}

func main() {
	n := 5
	src := 0

	edges := [][]int{
		{0, 1, -1},
		{0, 2, 4},
		{1, 2, 3},
		{1, 3, 2},
		{1, 4, 2},
		{3, 2, 5},
		{3, 1, 1},
		{4, 3, -3},
	}

	distances := bellmanFord(n, src, edges)

	if len(distances) != 0 {
		fmt.Printf("Distances from source %d: ", src)
		for i := 0; i < n; i++ {
			if distances[i] == math.MaxInt {
				fmt.Print("INF ")
			} else {
				fmt.Print(distances[i], " ")
			}
		}
		fmt.Println()
	}
}
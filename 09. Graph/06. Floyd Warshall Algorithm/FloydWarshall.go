package main

import (
	"fmt"
)

const INF = int(1e9)

func floydWarshall(n int, dist [][]int) {
	// Iterate through all intermediate nodes
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if dist[i][k] != INF && dist[k][j] != INF {
					if dist[i][k]+dist[k][j] < dist[i][j] {
						dist[i][j] = dist[i][k] + dist[k][j]
					}
				}
			}
		}
	}
}

func main() {
	n := 4

	dist := [][]int{
		{0, 3, INF, 7},
		{8, 0, 2, INF},
		{5, INF, 0, 1},
		{2, INF, INF, 0},
	}

	floydWarshall(n, dist)

	fmt.Println("Shortest distances between every pair of vertices:")
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if dist[i][j] == INF {
				fmt.Print("INF ")
			} else {
				fmt.Print(dist[i][j], " ")
			}
		}
		fmt.Println()
	}
}
package main

import (
	"fmt"
)

func DFS(node int, adj [][]int, vis []bool) {
	vis[node] = true
	fmt.Print(node, " ")

	for _, neigh := range adj[node] {
		if !vis[neigh] {
			DFS(neigh, adj, vis)
		}
	}
}

func main() {
	n := 6
	adj := make([][]int, n)

	adj[0] = []int{1, 2}
	adj[1] = []int{0, 3, 4}
	adj[2] = []int{0, 4}
	adj[3] = []int{1}
	adj[4] = []int{1, 2, 5}
	adj[5] = []int{4}

	vis := make([]bool, n)

	fmt.Print("DFS starting from node 0: ")
	DFS(0, adj, vis)
}
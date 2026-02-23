package main

import (
	"fmt"
)

func BFS(node int, adj [][]int, vis []bool) {
	queue := []int{}
	queue = append(queue, node)
	vis[node] = true

	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]

		fmt.Print(cur, " ")

		for _, neigh := range adj[cur] {
			if !vis[neigh] {
				queue = append(queue, neigh)
				vis[neigh] = true
			}
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

	fmt.Print("BFS starting from node 0: ")
	BFS(0, adj, vis)
}
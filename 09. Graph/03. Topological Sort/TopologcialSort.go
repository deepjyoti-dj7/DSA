package main

import (
	"fmt"
)

// ---------- DFS Based Topological Sort ----------

func dfs(node int, adj [][]int, vis []bool, stack *[]int) {
	vis[node] = true

	for _, neigh := range adj[node] {
		if !vis[neigh] {
			dfs(neigh, adj, vis, stack)
		}
	}

	// Push after visiting all neighbors
	*stack = append(*stack, node)
}

func topologicalSortDFS(n int, adj [][]int) []int {
	vis := make([]bool, n)
	stack := []int{}

	for i := 0; i < n; i++ {
		if !vis[i] {
			dfs(i, adj, vis, &stack)
		}
	}

	// Reverse stack to get topo order
	topo := []int{}
	for i := len(stack) - 1; i >= 0; i-- {
		topo = append(topo, stack[i])
	}

	return topo
}

// ---------- BFS Based Topological Sort (Kahn's Algorithm) ----------

func topologicalSortBFS(n int, adj [][]int) []int {
	indegree := make([]int, n)

	// Calculate indegree
	for i := 0; i < n; i++ {
		for _, neigh := range adj[i] {
			indegree[neigh]++
		}
	}

	queue := []int{}
	for i := 0; i < n; i++ {
		if indegree[i] == 0 {
			queue = append(queue, i)
		}
	}

	topo := []int{}

	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]

		topo = append(topo, cur)

		for _, neigh := range adj[cur] {
			indegree[neigh]--
			if indegree[neigh] == 0 {
				queue = append(queue, neigh)
			}
		}
	}

	return topo
}

func main() {
	n := 6
	adj := make([][]int, n)

	// Directed graph
	adj[5] = []int{2, 0}
	adj[4] = []int{0, 1}
	adj[2] = []int{3}
	adj[3] = []int{1}
	adj[0] = []int{}
	adj[1] = []int{}

	topo := topologicalSortDFS(n, adj)

	fmt.Print("Topological Sort (DFS): ")
	for _, node := range topo {
		fmt.Print(node, " ")
	}
	fmt.Println()

	topo = topologicalSortBFS(n, adj)

	fmt.Print("Topological Sort (BFS): ")
	for _, node := range topo {
		fmt.Print(node, " ")
	}
	fmt.Println()
}
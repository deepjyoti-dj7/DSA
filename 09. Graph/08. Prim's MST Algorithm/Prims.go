package main

import (
	"container/heap"
	"fmt"
	"math"
)

// ---------- Min Heap Implementation ----------

type Item struct {
	weight int
	vertex int
}

type MinHeap []Item

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].weight < h[j].weight }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Item))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[:n-1]
	return item
}

// ---------- Prim's Algorithm ----------

func primsAlgorithm(n int, adj [][][2]int) {
	key := make([]int, n)
	inMST := make([]bool, n)
	parent := make([]int, n)

	for i := 0; i < n; i++ {
		key[i] = math.MaxInt
		parent[i] = -1
	}

	h := &MinHeap{}
	heap.Init(h)

	key[0] = 0
	heap.Push(h, Item{0, 0})

	for h.Len() > 0 {
		item := heap.Pop(h).(Item)
		u := item.vertex

		if inMST[u] {
			continue
		}
		inMST[u] = true

		for _, edge := range adj[u] {
			v := edge[0]
			weight := edge[1]

			if !inMST[v] && weight < key[v] {
				key[v] = weight
				parent[v] = u
				heap.Push(h, Item{key[v], v})
			}
		}
	}

	// Print MST
	totalWeight := 0
	fmt.Println("Edges in the Minimum Spanning Tree:")
	for i := 1; i < n; i++ {
		fmt.Printf("%d - %d (weight: %d)\n", parent[i], i, key[i])
		totalWeight += key[i]
	}
	fmt.Println("Total weight of MST:", totalWeight)
}

// ---------- Main ----------

func main() {
	n := 5
	adj := make([][][2]int, n)

	// Undirected weighted graph
	adj[0] = append(adj[0], [2]int{1, 2})
	adj[1] = append(adj[1], [2]int{0, 2})

	adj[0] = append(adj[0], [2]int{3, 6})
	adj[3] = append(adj[3], [2]int{0, 6})

	adj[1] = append(adj[1], [2]int{2, 3})
	adj[2] = append(adj[2], [2]int{1, 3})

	adj[1] = append(adj[1], [2]int{3, 8})
	adj[3] = append(adj[3], [2]int{1, 8})

	adj[1] = append(adj[1], [2]int{4, 5})
	adj[4] = append(adj[4], [2]int{1, 5})

	adj[2] = append(adj[2], [2]int{4, 7})
	adj[4] = append(adj[4], [2]int{2, 7})

	primsAlgorithm(n, adj)
}
package main

import (
	"container/heap"
	"fmt"
	"math"
)

// ---------- Min Heap Implementation ----------

type Item struct {
	dist int
	node int
}

type MinHeap []Item

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].dist < h[j].dist }
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

// ---------- Dijkstra Using Priority Queue ----------

func dijkstraPQ(n, src int, adj [][][2]int) []int {
	dist := make([]int, n)
	for i := range dist {
		dist[i] = math.MaxInt
	}
	dist[src] = 0

	h := &MinHeap{}
	heap.Init(h)
	heap.Push(h, Item{0, src})

	for h.Len() > 0 {
		item := heap.Pop(h).(Item)
		dis := item.dist
		node := item.node

		if dis > dist[node] {
			continue
		}

		for _, edge := range adj[node] {
			neigh := edge[0]
			weight := edge[1]

			if dis+weight < dist[neigh] {
				dist[neigh] = dis + weight
				heap.Push(h, Item{dist[neigh], neigh})
			}
		}
	}

	return dist
}

// ---------- Dijkstra "Set-like" Version ----------
// (Go doesn't have ordered set like C++, so we simulate it)

func dijkstraSet(n, src int, adj [][][2]int) []int {
	dist := make([]int, n)
	for i := range dist {
		dist[i] = math.MaxInt
	}
	dist[src] = 0

	h := &MinHeap{}
	heap.Init(h)
	heap.Push(h, Item{0, src})

	for h.Len() > 0 {
		item := heap.Pop(h).(Item)
		dis := item.dist
		node := item.node

		if dis > dist[node] {
			continue
		}

		for _, edge := range adj[node] {
			neigh := edge[0]
			weight := edge[1]

			if dis+weight < dist[neigh] {
				dist[neigh] = dis + weight
				heap.Push(h, Item{dist[neigh], neigh})
			}
		}
	}

	return dist
}

// ---------- Main ----------

func main() {
	n := 5
	src := 0

	adj := make([][][2]int, n)

	// Directed weighted graph
	adj[0] = [][2]int{{1, 2}, {4, 1}}
	adj[1] = [][2]int{{2, 3}}
	adj[2] = [][2]int{{3, 6}}
	adj[4] = [][2]int{{2, 2}, {3, 4}}

	// Priority Queue version
	distances := dijkstraPQ(n, src, adj)
	fmt.Printf("PQ Distances from source %d: ", src)
	for _, d := range distances {
		fmt.Print(d, " ")
	}
	fmt.Println()

	// Set-like version
	distances = dijkstraSet(n, src, adj)
	fmt.Printf("Set Distances from source %d: ", src)
	for _, d := range distances {
		fmt.Print(d, " ")
	}
	fmt.Println()
}
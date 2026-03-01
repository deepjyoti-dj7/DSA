package main

import (
	"fmt"
	"sort"
)

// ---------- Disjoint Set (Union-Find) ----------

type DisjointSet struct {
	parent []int
	rank   []int
}

func NewDisjointSet(n int) *DisjointSet {
	ds := &DisjointSet{
		parent: make([]int, n),
		rank:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		ds.parent[i] = i
	}
	return ds
}

func (ds *DisjointSet) Find(x int) int {
	if ds.parent[x] != x {
		ds.parent[x] = ds.Find(ds.parent[x]) // Path compression
	}
	return ds.parent[x]
}

func (ds *DisjointSet) UnionByRank(x, y int) {
	rootX := ds.Find(x)
	rootY := ds.Find(y)

	if rootX != rootY {
		if ds.rank[rootX] > ds.rank[rootY] {
			ds.parent[rootY] = rootX
		} else if ds.rank[rootX] < ds.rank[rootY] {
			ds.parent[rootX] = rootY
		} else {
			ds.parent[rootY] = rootX
			ds.rank[rootX]++
		}
	}
}

// ---------- Edge Structure ----------

type Edge struct {
	u, v, weight int
}

// ---------- Kruskal's Algorithm ----------

func kruskalMST(n int, edges []Edge) {
	// Sort edges by weight
	sort.Slice(edges, func(i, j int) bool {
		return edges[i].weight < edges[j].weight
	})

	ds := NewDisjointSet(n)
	totalWeight := 0
	mst := []Edge{}

	for _, edge := range edges {
		if ds.Find(edge.u) != ds.Find(edge.v) {
			ds.UnionByRank(edge.u, edge.v)
			mst = append(mst, edge)
			totalWeight += edge.weight
		}
	}

	// Print MST
	fmt.Println("Edges in the Minimum Spanning Tree:")
	for _, edge := range mst {
		fmt.Printf("%d - %d (weight: %d)\n", edge.u, edge.v, edge.weight)
	}
	fmt.Println("Total weight of MST:", totalWeight)
}

// ---------- Main ----------

func main() {
	n := 5

	edges := []Edge{
		{0, 1, 2},
		{0, 3, 6},
		{1, 2, 3},
		{1, 3, 8},
		{1, 4, 5},
		{2, 4, 7},
	}

	kruskalMST(n, edges)
}
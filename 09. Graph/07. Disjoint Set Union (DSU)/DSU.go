package main

import (
	"fmt"
)

// ---------- Disjoint Set Structure ----------

type DisjointSet struct {
	parent []int
	rank   []int
	size   []int
}

// Constructor
func NewDisjointSet(n int) *DisjointSet {
	ds := &DisjointSet{
		parent: make([]int, n),
		rank:   make([]int, n),
		size:   make([]int, n),
	}

	for i := 0; i < n; i++ {
		ds.parent[i] = i
		ds.rank[i] = 0
		ds.size[i] = 1
	}

	return ds
}

// Find with Path Compression
func (ds *DisjointSet) Find(x int) int {
	if ds.parent[x] != x {
		ds.parent[x] = ds.Find(ds.parent[x])
	}
	return ds.parent[x]
}

// Union by Rank
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

// Union by Size
func (ds *DisjointSet) UnionBySize(x, y int) {
	rootX := ds.Find(x)
	rootY := ds.Find(y)

	if rootX != rootY {
		if ds.size[rootX] > ds.size[rootY] {
			ds.parent[rootY] = rootX
			ds.size[rootX] += ds.size[rootY]
		} else {
			ds.parent[rootX] = rootY
			ds.size[rootY] += ds.size[rootX]
		}
	}
}

// Check if two elements are connected
func (ds *DisjointSet) IsConnected(x, y int) bool {
	return ds.Find(x) == ds.Find(y)
}

// ---------- Main ----------

func main() {
	n := 7
	ds := NewDisjointSet(n)

	// Perform some union operations
	ds.UnionByRank(1, 2)
	ds.UnionByRank(2, 3)
	ds.UnionBySize(4, 5)
	ds.UnionBySize(6, 4)

	// Check connectivity
	fmt.Println("Is 1 connected to 3?", ds.IsConnected(1, 3))
	fmt.Println("Is 1 connected to 5?", ds.IsConnected(1, 5))

	// Find roots
	fmt.Println("Root of 2:", ds.Find(2))
	fmt.Println("Root of 4:", ds.Find(4))
}
class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]  # Each element is its own parent
        self.rank = [0] * n  # Rank is initially 0
        self.size = [1] * n  # Size of each set is initially 1

    # Find the representative (root) of the set containing x, with path compression
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    # Union two sets containing x and y, using union by rank
    def unionByRank(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX  # Attach smaller tree under larger tree
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX  # If ranks are equal, attach under one and increment rank
                self.rank[rootX] += 1

    # Union two sets containing x and y, using union by size
    def unionBySize(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.size[rootX] > self.size[rootY]:
                self.parent[rootY] = rootX
                self.size[rootX] += self.size[rootY]
            else:
                self.parent[rootX] = rootY
                self.size[rootY] += self.size[rootX]

    # Helper function to check if two elements are in the same set
    def is_connected(self, x, y):
        return self.find(x) == self.find(y)

class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight

    # Comparator to sort edges by weight
    def __lt__(self, other):
        return self.weight < other.weight

def kruskalMST(n, edges):
    # Sort edges by weight
    edges.sort()

    ds = DisjointSet(n)

    mst = []
    total_weight = 0

    for edge in edges:
        u = edge.u
        v = edge.v

        # If they are in different sets, include this edge in MST
        if ds.find(u) != ds.find(v):
            ds.unionByRank(u, v)
            mst.append(edge)
            total_weight += edge.weight

    # Output the MST
    print("Edges in the Minimum Spanning Tree:")
    for edge in mst:
        print(f"{edge.u} - {edge.v} (weight: {edge.weight})")
    print(f"Total weight of MST: {total_weight}")


def main():
    # Number of vertices
    n = 5
    edges = [
        Edge(0, 1, 2),
        Edge(0, 3, 6),
        Edge(1, 2, 3),
        Edge(1, 3, 8),
        Edge(1, 4, 5),
        Edge(2, 4, 7)
    ]

    # Call Kruskal's Algorithm
    kruskalMST(n, edges)

main()
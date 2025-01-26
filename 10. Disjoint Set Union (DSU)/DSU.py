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
    def union_by_rank(self, x, y):
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
    def union_by_size(self, x, y):
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


def main(): 
    n = 7  # Number of elements
    ds = DisjointSet(n)

    # Perform some union operations
    ds.union_by_rank(1, 2)
    ds.union_by_rank(2, 3)
    ds.union_by_size(4, 5)
    ds.union_by_size(6, 4)

    # Check connectivity
    print("Is 1 connected to 3?", "Yes" if ds.is_connected(1, 3) else "No")
    print("Is 1 connected to 5?", "Yes" if ds.is_connected(1, 5) else "No")

    # Find the root of a specific element
    print("Root of 2:", ds.find(2))
    print("Root of 4:", ds.find(4))

if __name__ == "__main__":
    main()
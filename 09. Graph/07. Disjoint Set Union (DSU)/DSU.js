class DisjointSet {
    constructor(n) {
        this.parent = Array.from({ length: n }, (_, i) => i); // Each element is its own parent
        this.rank = Array(n).fill(0); // Rank is initially 0
        this.size = Array(n).fill(1); // Size of each set is initially 1
    }

    // Find the representative (root) of the set containing x, with path compression
    find(x) {
        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x]); // Path compression
        }
        return this.parent[x];
    }

    // Union two sets containing x and y, using union by rank
    unionByRank(x, y) {
        let rootX = this.find(x);
        let rootY = this.find(y);

        if (rootX !== rootY) {
            if (this.rank[rootX] > this.rank[rootY]) {
                this.parent[rootY] = rootX; // Attach smaller tree under larger tree
            } else if (this.rank[rootX] < this.rank[rootY]) {
                this.parent[rootX] = rootY;
            } else {
                this.parent[rootY] = rootX; // If ranks are equal, attach under one and increment rank
                this.rank[rootX]++;
            }
        }
    }

    // Union two sets containing x and y, using union by size
    unionBySize(x, y) {
        let rootX = this.find(x);
        let rootY = this.find(y);

        if (rootX !== rootY) {
            if (this.size[rootX] > this.size[rootY]) {
                this.parent[rootY] = rootX;
                this.size[rootX] += this.size[rootY];
            } else {
                this.parent[rootX] = rootY;
                this.size[rootY] += this.size[rootX];
            }
        }
    }

    // Helper function to check if two elements are in the same set
    isConnected(x, y) {
        return this.find(x) === this.find(y);
    }
}


function main() {
    const n = 7; // Number of elements
    const ds = new DisjointSet(n);

    // Perform some union operations
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 4);

    // Check connectivity
    console.log("Is 1 connected to 3?", ds.isConnected(1, 3) ? "Yes" : "No");
    console.log("Is 1 connected to 5?", ds.isConnected(1, 5) ? "Yes" : "No");

    // Find the root of a specific element
    console.log("Root of 2:", ds.find(2));
    console.log("Root of 4:", ds.find(4));
}

main();

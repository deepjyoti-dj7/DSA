
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

class Edge {
    constructor(u, v, weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }
}

// Comparator to sort edges by weight
function compareEdges(a, b) {
    return a.weight - b.weight;
}

function kruskalMST(n, edges) {
    // Sort edges by weight
    edges.sort(compareEdges);

    const ds = new DisjointSet(n);

    let mst = [];
    let totalWeight = 0;

    for (let edge of edges) {
        let u = edge.u;
        let v = edge.v;

        // If they are in different sets, include this edge in MST
        if (ds.find(u) !== ds.find(v)) {
            ds.unionByRank(u, v);
            mst.push(edge);
            totalWeight += edge.weight;
        }
    }

    // Output the MST
    console.log("Edges in the Minimum Spanning Tree:");
    for (let edge of mst) {
        console.log(`${edge.u} - ${edge.v} (weight: ${edge.weight})`);
    }
    console.log("Total weight of MST:", totalWeight);
}

function main() {
    const n = 5; // Number of vertices
    const edges = [
        new Edge(0, 1, 2),
        new Edge(0, 3, 6),
        new Edge(1, 2, 3),
        new Edge(1, 3, 8),
        new Edge(1, 4, 5),
        new Edge(2, 4, 7)
    ];
    
    // Call Kruskal's Algorithm
    kruskalMST(n, edges);
}

main();

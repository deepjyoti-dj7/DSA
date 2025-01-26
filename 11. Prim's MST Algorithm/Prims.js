class PriorityQueue {
    constructor() {
        this.queue = [];
    }

    enqueue(element, priority) {
        this.queue.push({ element, priority });
        this.queue.sort((a, b) => a.priority - b.priority); // Min-heap: smallest priority first
    }

    dequeue() {
        return this.queue.shift(); // Remove the element with the highest priority (smallest value)
    }

    isEmpty() {
        return this.queue.length === 0;
    }
}

class Edge {
    constructor(vertex, weight) {
        this.vertex = vertex;
        this.weight = weight;
    }
}

function primsAlgorithm(n, adj) {
    const key = new Array(n).fill(Infinity); // Stores the smallest edge weight to each vertex
    const parent = new Array(n).fill(-1); // Stores the MST parent of each vertex
    const inMST = new Array(n).fill(false); // Tracks if a vertex is already in the MST
    key[0] = 0;

    const pq = new PriorityQueue();
    pq.enqueue(0, 0); // Start from vertex 0 with weight 0

    while (!pq.isEmpty()) {
        const { element: u } = pq.dequeue();
        inMST[u] = true;

        // Iterate through adjacent edges of u
        for (const edge of adj[u]) {
            const { vertex: v, weight } = edge;

            // If v is not in MST and weight of (u, v) is smaller than its current key
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.enqueue(v, weight);
                parent[v] = u;
            }
        }
    }

    // Output MST edges and total weight
    let totalWeight = 0;
    console.log("Edges in the Minimum Spanning Tree:");
    for (let i = 1; i < n; i++) {
        console.log(`${parent[i]} - ${i} (weight: ${key[i]})`);
        totalWeight += key[i];
    }
    console.log("Total weight of MST:", totalWeight);
}


function main() {
    const n = 5;
    const adj = Array.from({ length: n }, () => []);
    
    adj[0].push(new Edge(1, 2)); adj[1].push(new Edge(0, 2));
    adj[0].push(new Edge(3, 6)); adj[3].push(new Edge(0, 6));
    adj[1].push(new Edge(2, 3)); adj[2].push(new Edge(1, 3));
    adj[1].push(new Edge(3, 8)); adj[3].push(new Edge(1, 8));
    adj[1].push(new Edge(4, 5)); adj[4].push(new Edge(1, 5));
    adj[2].push(new Edge(4, 7)); adj[4].push(new Edge(2, 7));
    
    primsAlgorithm(n, adj);
}

main();
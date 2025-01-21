class PriorityQueue {
    constructor() {
        this.queue = [];
    }

    enqueue(element) {
        this.queue.push(element);
        this.queue.sort((a, b) => a[0] - b[0]);
    }

    dequeue() {
        if (this.isEmpty()) 
            return "Queue is empty";
        return this.queue.shift();
    }

    isEmpty() {
        return this.queue.length === 0;
    }
}

function dijkstraPriorityQueue(n, src, adj) {
    const pq = new PriorityQueue();
    
    const dist = Array(n).fill(Infinity);
    dist[src] = 0;
    pq.enqueue([0, src]);

    while (!pq.isEmpty()) {
        const [dis, node] = pq.dequeue();

        for (const [neigh, edgeWt] of adj[node]) {
            if (dis + edgeWt < dist[neigh]) {
                dist[neigh] = dis + edgeWt;
                pq.enqueue([dist[neigh], neigh]);
            }
        }
    }
    return dist;
}

function dijkstraSet(n, src, adj) {
    const set = new Set();
    const sortedSet = new Map();
    
    const dist = Array(n).fill(Infinity);
    dist[src] = 0;
    sortedSet.set(src, 0);

    while (sortedSet.size > 0) {
        const [node, dis] = [...sortedSet.entries()].sort((a, b) => a[1] - b[1])[0];
        sortedSet.delete(node);

        for (const [neigh, edgeWt] of adj[node]) {
            if (dis + edgeWt < dist[neigh]) {
                if (sortedSet.has(neigh)) {
                    sortedSet.delete(neigh);
                }
                dist[neigh] = dis + edgeWt;
                sortedSet.set(neigh, dist[neigh]);
            }
        }
    }
    return dist;
}

function main() {
    const n = 5; // Number of nodes
    const src = 0; // Source node
    const adj = Array.from({ length: n }, () => []);

    // Graph representation
    adj[0].push([1, 2], [4, 1]);
    adj[1].push([2, 3]);
    adj[2].push([3, 6]);
    adj[4].push([2, 2], [3, 4]);

    // Priority Queue
    console.log("Distances (Priority Queue):", dijkstraPriorityQueue(n, src, adj));

    // Set
    console.log("Distances (Set):", dijkstraSet(n, src, adj));
}

main();

function bellmanFord(n, src, edges) {
    const dist = Array(n).fill(Infinity);
    dist[src] = 0;

    // Relax all edges (n-1) times
    for (let i = 0; i < n - 1; i++) {
        for (const [u, v, weight] of edges) {
            if (dist[u] !== Infinity && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const [u, v, weight] of edges) {
        if (dist[u] !== Infinity && dist[u] + weight < dist[v]) {
            console.log("Negative weight cycle detected!");
            return null;
        }
    }

    return dist;
}


function main() {
    const n = 5; // Number of vertices
    const src = 0; // Source vertex
    const edges = [
        [0, 1, -1], [0, 2, 4], [1, 2, 3], [1, 3, 2],
        [1, 4, 2], [3, 2, 5], [3, 1, 1], [4, 3, -3]
    ];

    const distances = bellmanFord(n, src, edges);

    if (distances) {
        console.log("Distances from source " + src + ":", distances);
    }
}

main();
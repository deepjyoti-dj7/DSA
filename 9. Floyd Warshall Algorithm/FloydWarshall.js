function FloydWarshall(n, dist) {
    // Iterating through all intermediate nodes
    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (dist[i][k] !== Infinity && dist[k][j] !== Infinity) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

function main() {
    const n = 4; // Number of vertices
    const dist = [
        [0, 3, Infinity, 7],
        [8, 0, 2, Infinity],
        [5, Infinity, 0, 1],
        [2, Infinity, Infinity, 0]
    ];

    FloydWarshall(n, dist);

    console.log("Shortest distances between every pair of vertices:");
    for (let i = 0; i < n; i++) {
        console.log(
            dist[i].map(d => (d === Infinity ? "INF" : d)).join(" ")
        );
    }
}

main();

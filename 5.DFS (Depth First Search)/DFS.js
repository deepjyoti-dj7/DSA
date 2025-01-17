function DFS(node, adj, vis) {
    vis[node] = true;
    process.stdout.write(node + " ");

    for (const neigh of adj[node]) {
        if (!vis[neigh]) {
            DFS(neigh, adj, vis);
        }
    }
}

function main() {
    const n = 6;
    const adj = Array.from({ length: n }, () => []);

    adj[0] = [1, 2];
    adj[1] = [0, 3, 4];
    adj[2] = [0, 4];
    adj[3] = [1];
    adj[4] = [1, 2, 5];
    adj[5] = [4];

    const vis = Array(n).fill(false);

    process.stdout.write("DFS starting from node 0: ");
    DFS(0, adj, vis);
}

main();

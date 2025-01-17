function BFS(node, adj, vis) {
    const q = [];
    q.push(node);
    vis[node] = true; 

    while(q.length) {
        const cur = q.shift();
        process.stdout.write(cur + " ");

        for (const neigh of adj[cur]) {
            if (!vis[neigh]) {
                q.push(neigh);
                vis[neigh] = true;
            }
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

    process.stdout.write("BFS starting from node 0: ");
    BFS(0, adj, vis);
}

main();

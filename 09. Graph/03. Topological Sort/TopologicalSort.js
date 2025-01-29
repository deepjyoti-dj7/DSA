function dfs(node, adj, vis, stack) {
    vis[node] = true;
    for (let neigh of adj[node]) {
        if (!vis[neigh]) {
            dfs(neigh, adj, vis, stack);
        }
    }
    stack.push(node);
}

function topologicalSortDFS(n, adj) {
    const vis = new Array(n).fill(false);
    const stack = [];

    for (let i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, stack);
        }
    }

    return stack.reverse();
}

function topologicalSortBFS(n, adj) {
    const indegree = new Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        for (let neigh of adj[i]) {
            indegree[neigh]++;
        }
    }

    const queue = [];
    for (let i = 0; i < n; i++) {
        if (indegree[i] === 0) {
            queue.push(i);
        }
    }

    const topo = [];
    while (queue.length > 0) {
        const cur = queue.shift();
        topo.push(cur);

        for (let neigh of adj[cur]) {
            indegree[neigh]--;
            if (indegree[neigh] === 0) {
                queue.push(neigh);
            }
        }
    }

    return topo;
}

// Main
function main() {
    const n = 6;
    const adj = Array.from({ length: n }, () => []);

    adj[5].push(2, 0);
    adj[4].push(0, 1);
    adj[2].push(3);
    adj[3].push(1);

    console.log("Topological Sort (DFS):", topologicalSortDFS(n, adj));
    console.log("Topological Sort (BFS):", topologicalSortBFS(n, adj));
}

main();

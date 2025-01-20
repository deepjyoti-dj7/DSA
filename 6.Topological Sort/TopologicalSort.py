from collections import deque

def dfs(node, adj, vis, stack):
    vis[node] = True
    for neigh in adj[node]:
        if not vis[neigh]:
            dfs(neigh, adj, vis, stack)
    stack.append(node)

def topological_sort_dfs(n, adj):
    vis = [False] * n
    stack = []

    for i in range(n):
        if not vis[i]:
            dfs(i, adj, vis, stack)

    return stack[::-1]

def topological_sort_bfs(n, adj):
    indegree = [0] * n
    for i in range(n):
        for neigh in adj[i]:
            indegree[neigh] += 1

    queue = deque([i for i in range(n) if indegree[i] == 0])
    topo = []

    while queue:
        cur = queue.popleft()
        topo.append(cur)

        for neigh in adj[cur]:
            indegree[neigh] -= 1
            if indegree[neigh] == 0:
                queue.append(neigh)

    return topo

# Main
n = 6
adj = [[] for _ in range(n)]

adj[5].extend([2, 0])
adj[4].extend([0, 1])
adj[2].append(3)
adj[3].append(1)

print("Topological Sort (DFS):", topological_sort_dfs(n, adj))
print("Topological Sort (BFS):", topological_sort_bfs(n, adj))

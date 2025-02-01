def DFS(node, adj, vis):
    vis[node] = True
    print(node, end=" ")

    for neigh in adj[node]:
        if not vis[neigh]:
            DFS(neigh, adj, vis)

def main():
    n = 6
    adj = [[] for _ in range(n)]

    adj[0] = [1, 2]
    adj[1] = [0, 3, 4]
    adj[2] = [0, 4]
    adj[3] = [1]
    adj[4] = [1, 2, 5]
    adj[5] = [4]

    vis = [False] * n

    print("DFS starting from node 0: ", end="")
    DFS(0, adj, vis)

main()

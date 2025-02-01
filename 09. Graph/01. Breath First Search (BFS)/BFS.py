from collections import deque

def BFS(node, adj, vis):
    q = deque()
    q.append(node)
    vis[node] = True

    while q:
        cur = q.popleft()
        print(cur, end=" ")

        for neigh in adj[cur]:
            if not vis[neigh]:
                q.append(neigh)
                vis[neigh] = True

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

    print("BFS starting from node 0: ", end="")
    BFS(0, adj, vis)

main()
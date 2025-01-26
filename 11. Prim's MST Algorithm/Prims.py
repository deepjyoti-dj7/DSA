import heapq

def prims_algorithm(n, adj):
    key = [float('inf')] * n
    parent = [-1] * n
    in_mst = [False] * n
    key[0] = 0

    pq = [(0, 0)]  # (key, vertex)

    while pq:
        _, u = heapq.heappop(pq)
        in_mst[u] = True

        for v, weight in adj[u]:
            if not in_mst[v] and weight < key[v]:
                key[v] = weight
                heapq.heappush(pq, (key[v], v))
                parent[v] = u

    # Output MST edges and total weight
    total_weight = 0
    print("Edges in the Minimum Spanning Tree:")
    for i in range(1, n):
        print(f"{parent[i]} - {i} (weight: {key[i]})")
        total_weight += key[i]
    print("Total weight of MST:", total_weight)


def main(): 
    n = 5
    adj = [[] for _ in range(n)]

    adj[0].append((1, 2)); adj[1].append((0, 2))
    adj[0].append((3, 6)); adj[3].append((0, 6))
    adj[1].append((2, 3)); adj[2].append((1, 3))
    adj[1].append((3, 8)); adj[3].append((1, 8))
    adj[1].append((4, 5)); adj[4].append((1, 5))
    adj[2].append((4, 7)); adj[4].append((2, 7))

    prims_algorithm(n, adj)

if __name__ == "__main__":
    main()
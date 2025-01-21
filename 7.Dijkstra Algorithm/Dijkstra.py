import heapq

def dijkstra_priority_queue(n, src, adj):
    dist = [float('inf')] * n
    dist[src] = 0
    pq = [(0, src)]  # Min-heap storing (distance, node)

    while pq:
        dis, node = heapq.heappop(pq)

        for neigh, edge_wt in adj[node]:
            if dis + edge_wt < dist[neigh]:
                dist[neigh] = dis + edge_wt
                heapq.heappush(pq, (dist[neigh], neigh))
    
    return dist

def dijkstra_set(n, src, adj):
    dist = [float('inf')] * n
    dist[src] = 0
    visited = set()
    active_nodes = {(0, src)}  # Using a set to store (distance, node)

    while active_nodes:
        dis, node = min(active_nodes)  # Extract node with minimum distance
        active_nodes.remove((dis, node))

        if node in visited:
            continue
        visited.add(node)

        for neigh, edge_wt in adj[node]:
            if dis + edge_wt < dist[neigh]:
                if dist[neigh] != float('inf'):
                    active_nodes.discard((dist[neigh], neigh))
                dist[neigh] = dis + edge_wt
                active_nodes.add((dist[neigh], neigh))
    
    return dist

# Main
n = 5  # Number of nodes
src = 0  # Source node
adj = [[] for _ in range(n)]

# Graph representation
adj[0].extend([(1, 2), (4, 1)])
adj[1].extend([(2, 3)])
adj[2].extend([(3, 6)])
adj[4].extend([(2, 2), (3, 4)])

# Priority Queue
print("Distances (Priority Queue):", dijkstra_priority_queue(n, src, adj))

# Set
print("Distances (Set):", dijkstra_set(n, src, adj))

def bellman_ford(n, src, edges):
    # Initialize distances to infinity
    dist = [float('inf')] * n
    dist[src] = 0

    # Relax all edges (n-1) times
    for _ in range(n - 1):
        for u, v, weight in edges:
            if dist[u] != float('inf') and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight

    # Check for negative weight cycles
    for u, v, weight in edges:
        if dist[u] != float('inf') and dist[u] + weight < dist[v]:
            print("Negative weight cycle detected!")
            return None

    return dist

def main():
    n = 5  # Number of vertices
    src = 0  # Source vertex
    edges = [
        (0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2),
        (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)
    ]

    distances = bellman_ford(n, src, edges)

    if distances:
        print(f"Distances from source {src}:", distances)


main()
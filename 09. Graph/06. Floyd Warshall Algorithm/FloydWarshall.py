def FloydWarshall(n, dist):
    # Iterating through all intermediate nodes
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

def main():
    n = 4  # Number of vertices
    dist = [
        [0, 3, float('inf'), 7],
        [8, 0, 2, float('inf')],
        [5, float('inf'), 0, 1],
        [2, float('inf'), float('inf'), 0]
    ]

    FloydWarshall(n, dist)

    print("Shortest distances between every pair of vertices:")
    for row in dist:
        print(" ".join("INF" if d == float('inf') else str(d) for d in row))

main()
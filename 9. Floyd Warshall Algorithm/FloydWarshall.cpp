#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 

void FloydWarshall(int n, vector<vector<int>> &dist) {
    // Iterating through all intermediate nodes
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    FloydWarshall(n, dist);

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) 
                cout << "INF ";
            else 
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

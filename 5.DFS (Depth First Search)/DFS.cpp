#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            DFS(neigh, adj, vis);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2, 5};
    adj[5] = {4};

    vector<bool> vis(n, 0);
     
    cout << "BFS starting from node 0: ";
    DFS(0, adj, vis);

    return 0;
}
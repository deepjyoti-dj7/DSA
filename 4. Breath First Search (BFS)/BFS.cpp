#include <bits/stdc++.h>
using namespace std;

void BFS(int node, vector<vector<int>> &adj, vector<bool> &vis) {
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (auto& neigh : adj[cur]) {
            if (!vis[neigh]) {
                q.push(neigh);
                vis[neigh] = true;
            }
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

    vector<bool> vis(n, false);
     
    cout << "BFS starting from node 0: ";
    BFS(0, adj, vis);

    return 0;
}
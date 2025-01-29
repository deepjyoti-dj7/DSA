#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
    vis[node] = true;
    for (auto &neigh : adj[node]) {
        if (!vis[neigh]) {
            dfs(neigh, adj, vis, st);
        }
    }
    // Push the node to stack after visiting all its neighbors
    st.push(node);
}

vector<int> topologicalSortDFS(int n, vector<vector<int>> &adj) {
    vector<bool> vis(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

vector<int> topologicalSortBFS(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n, 0);

    // Calculate indegree of all nodes
    for (int i = 0; i < n; i++) {
        for (auto &neigh : adj[i]) {
            indegree[neigh]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);

        for (auto &neigh : adj[cur]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    return topo;
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adj(n);

    // Directed graph
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    adj[0] = {};
    adj[1] = {};

    vector<int> topo = topologicalSortDFS(n, adj);

    cout << "Topological Sort (DFS): ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    topo = topologicalSortBFS(n, adj);

    cout << "Topological Sort (BFS): ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

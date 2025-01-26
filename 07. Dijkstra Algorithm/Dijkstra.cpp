#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraPriorityQueue(int n, int src, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int neigh = it.first;
            int edgeWt = it.second;
            if (dis + edgeWt < dist[neigh]) {
                dist[neigh] = dis + edgeWt;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    return dist;
}

vector<int> dijkstraSet(int n, int src, vector<vector<pair<int, int>>> &adj) {
    set<pair<int, int>> st;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *st.begin();
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto it : adj[node]) {
            int neigh = it.first;
            int edgeWt = it.second;
            if (dis + edgeWt < dist[neigh]) {
                
                if (dist[neigh] != INT_MAX)
                    st.erase({dist[neigh], neigh});

                dist[neigh] = dis + edgeWt;
                st.insert({dist[neigh], neigh});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5; // Number of nodes
    int src = 0; // Source node
    vector<vector<pair<int, int>>> adj(n);

    // Graph representation
    adj[0] = {{1, 2}, {4, 1}};
    adj[1] = {{2, 3}};
    adj[2] = {{3, 6}};
    adj[4] = {{2, 2}, {3, 4}};

    // Priority Queue 
    vector<int> distances = dijkstraPriorityQueue(n, src, adj);

    cout << "Distances from source " << src << ": ";
    for (int d : distances) 
        cout << d << " ";
    cout << endl;

    // Set
    distances = dijkstraSet(n, src, adj);

    cout << "Distances from source " << src << ": ";
    for (int d : distances) 
        cout << d << " ";
    cout << endl;

    return 0;
}
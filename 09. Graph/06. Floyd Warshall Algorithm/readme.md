# Floyd–Warshall Algorithm

The **Floyd–Warshall Algorithm** is a dynamic programming algorithm used to find the **shortest paths between all pairs of nodes** in a weighted graph. It works for **directed or undirected graphs**, supports **negative edge weights**, and can detect **negative cycles**.

---

## 🚀 What Is Floyd–Warshall?

Floyd–Warshall answers the question:

**“What is the shortest path between every pair of vertices in a graph?”**

It systematically considers each vertex as an intermediate point and updates shortest paths by checking whether going through that vertex is better.

---

## 🌟 Key Features

* Computes **all-pairs shortest paths**
* Handles **negative edges** (but not negative cycles)
* Detects **negative cycles**
* Simple, elegant dynamic programming structure
* Produces a **distance matrix** output

---

## 🧠 When to Use Floyd–Warshall

Use this algorithm when:

* You need shortest paths between **all** vertices
* The graph is relatively **small** (dense or up to ~300–500 nodes)
* You need to **detect negative cycles**
* You want a clean dynamic programming approach
* The graph may have **negative edge weights**

---

## 📈 Time & Space Complexity

* **Time Complexity**: `O(V³)`
  Triple nested loops over vertices
* **Space Complexity**: `O(V²)`
  Uses a distance matrix

This makes it suitable for small–medium graphs but impractical for very large ones.

---

## 🔍 How It Works (Conceptual Steps)

1. **Initialize a distance matrix**:

   * `dist[i][i] = 0`
   * `dist[i][j] = weight(i, j)` if edge exists
   * Otherwise `dist[i][j] = ∞`
2. **Iterate through all vertices as intermediates (k)**
3. **For every pair (i, j)**, check if:

   ```
   dist[i][j] > dist[i][k] + dist[k][j]
   ```

   If so, update it.
4. After all iterations, `dist[i][j]` holds the shortest distance.

---

## 🧩 Key Properties

* Works for negative edges
* Cannot compute valid paths in presence of **negative cycles**
* Can **detect** negative cycles by checking if `dist[i][i] < 0` for any i
* Deterministic and guarantees optimal results

---

## 🧩 Example Uses

* Routing tables for networks
* Computing transitive closure (reachability)
* Social network analysis (all-pairs closeness)
* Preprocessing distances for fast queries in dense graphs
* Optimization problems involving pairwise distances

---

## 📚 Additional Notes

* The algorithm is symmetric for undirected graphs but works naturally for directed graphs.
* Often combined with **path reconstruction matrices** to retrieve actual shortest paths.
* More flexible than Dijkstra and Bellman–Ford, but more computationally expensive.

---

## 🏁 Summary

The Floyd–Warshall Algorithm is a powerful and elegant method for computing shortest paths between all pairs of vertices in a graph, supporting negative weights and detecting negative cycles. Its simplicity and broad applicability make it essential for dense graphs and all-pairs distance problems.

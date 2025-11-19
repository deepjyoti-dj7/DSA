# Bellman–Ford Algorithm

The **Bellman–Ford Algorithm** is a single-source shortest-path algorithm that works on **weighted graphs**, including those with **negative edge weights**. It is more flexible than Dijkstra’s Algorithm and can also detect **negative-weight cycles**.

---

## 🚀 What Is Bellman–Ford?

Bellman–Ford answers the question:

**“What is the shortest path from a source node to every other node, even if some edges have negative weights?”**

It repeatedly relaxes all edges, gradually improving distance estimates until they converge to their shortest possible values.

---

## 🌟 Key Features

* Handles **negative edge weights**
* Detects **negative-weight cycles**
* Works on directed and undirected graphs
* Simpler logic than Dijkstra, but slower

---

## 🧠 When to Use Bellman–Ford

Use Bellman–Ford when:

* Your graph contains **negative weights**
* You need to **detect negative cycles**
* Dijkstra’s algorithm cannot be applied
* You want a conceptually straightforward shortest-path algorithm

---

## 📈 Time & Space Complexity

* **Time Complexity**:
  **O(V × E)**
  (Much slower than Dijkstra for large graphs)
* **Space Complexity**: `O(V)`
  (Stores distances and predecessor information)

---

## 🔍 How It Works (Conceptual Steps)

1. **Initialize distances**

   * Source = 0
   * All others = ∞
2. **Relax all edges (V − 1 times)**

   * For each edge (u, v, w), update distance[v] if a shorter path is found
3. **Check for negative cycles**

   * Make one more pass
   * If any distance can still be improved → negative cycle detected

Why **V − 1**?
Because the longest possible shortest path in a graph without cycles uses **(V − 1)** edges.

---

## 🧩 Key Properties

* **Correct** even with negative edges
* **Detects negative cycles**, unlike Dijkstra
* Slower but more general

---

## 🧩 Example Uses

* Currency exchange arbitrage detection
* Routing algorithms for networks (e.g., distance-vector protocols)
* Solving graphs where penalties or credits create negative weights
* Finding shortest paths in economic or cost-based models

---

## 📚 Additional Notes

* If the graph contains a **negative-weight cycle**, shortest paths are undefined (they can decrease forever).
* For graphs with only non-negative weights, **Dijkstra’s Algorithm is faster**.
* Bellman–Ford forms the foundation for advanced algorithms like **Johnson’s algorithm**.

---

## 🏁 Summary

The Bellman–Ford Algorithm is a robust shortest-path solution capable of handling negative weights and identifying negative cycles. Although slower than Dijkstra, its generality makes it indispensable in environments where edge weights can be negative or dynamically changing.

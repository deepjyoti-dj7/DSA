# Dijkstra’s Algorithm

Dijkstra’s Algorithm is a classic shortest-path algorithm used to find the minimum-cost path from a starting node to all other nodes in a **weighted graph** with **non-negative edge weights**.

---

## 🚀 What Is Dijkstra’s Algorithm?

Dijkstra answers the question:
**“What is the shortest (minimum total weight) path from a source node to every other node?”**

It expands outward from the source, always choosing the **currently known shortest distance** node that has not been finalized yet.

---

## 🌟 Key Features

* Works on **weighted graphs**
* Finds the **shortest path** from a source to all reachable nodes
* Requires **non-negative weights**
* Uses a **priority queue** (conceptually) to pick the next closest node
* Efficient and widely applicable

---

## 🧠 When to Use Dijkstra

Use Dijkstra when:

* You need the **shortest path** in a weighted graph
* All edge weights are **non-negative**
* You want distances from a single source to all other nodes
* Examples include:

  * GPS navigation
  * Network routing protocols (e.g., OSPF)
  * Pathfinding in games
  * Cost-based optimization problems

---

## 📈 Time & Space Complexity

Complexity depends on the data structure used for selecting the minimum-distance node:

* **With a binary heap (priority queue)**:
  **Time:** `O((V + E) log V)`
* **Space:** `O(V)` (for distance, visited, and queue structures)

---

## 🔍 How It Works (Conceptual Steps)

1. **Initialize distances**:

   * Distance to source = 0
   * All others = ∞
2. **Pick the unvisited node with the smallest known distance**
   (the priority queue handles this efficiently)
3. **Relax edges**:
   For each neighbor:

   * Check if the path through the current node is shorter
   * If yes, update the neighbor’s distance
4. **Mark the current node as visited** (finalized)
5. Repeat until all reachable nodes are visited

---

## 🧩 Key Properties

* Guarantees shortest path with **non-negative** weights
* Cannot handle graphs with **negative-weight edges**
  (use Bellman–Ford instead)
* Builds a “shortest path tree” from the source

---

## 🧩 Example Uses

* Shortest driving route on maps
* Packet routing in networks
* Robot and game AI pathfinding
* Optimal resource transport or cost minimization

---

## 📚 Additional Notes

* Dijkstra is essentially a weighted version of BFS
  (BFS is Dijkstra with all edge weights = 1).
* Using a priority queue is crucial for efficiency.
* The algorithm’s correctness relies on the fact that once the shortest path to a node is chosen (visited), it is final.

---

## 🏁 Summary

Dijkstra’s Algorithm is the go-to solution for finding the shortest paths in weighted, non-negative graphs. Its reliability, efficiency, and adaptability make it one of the foundational algorithms in computer science and real-world applications.

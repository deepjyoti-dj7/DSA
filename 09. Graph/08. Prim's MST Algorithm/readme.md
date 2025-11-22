# Prim’s Algorithm

Prim’s Algorithm is a greedy algorithm used to find the **Minimum Spanning Tree (MST)** of a **connected, weighted, undirected graph**. The MST is a subset of edges that connects all vertices with the **minimum possible total edge weight** and **no cycles**.

---

## 🚀 What Is Prim’s Algorithm?

Prim’s algorithm grows the MST **one edge at a time** by always choosing the **cheapest edge** that connects a visited node to an unvisited node.

It starts from any node and expands like a tree that keeps picking the minimum edge leading outward.

---

## 🌟 Key Features

* Builds MST incrementally
* Always expands to the **nearest unvisited vertex**
* Greedy strategy
* Works only for:

  * **Undirected graphs**
  * **Connected graphs**

---

## 🧠 When to Use Prim’s Algorithm

Use Prim’s when:

* You need to construct a **minimum spanning tree**
* The graph is **dense** (lots of edges)
* You like a “grow from one point” strategy
* Example applications:

  * Network wiring / LAN layout
  * Designing road or pipeline systems
  * Clustering algorithms (e.g., in ML)

---

## 📈 Time & Space Complexity

Depends on the data structure:

### Using a **priority queue + adjacency list** (optimal):

* **Time:** `O(E log V)`
* **Space:** `O(V)`

### Using adjacency matrix:

* **Time:** `O(V²)`
* (OK for dense graphs)

---

## 🔍 How It Works (Conceptual Steps)

1. Choose any start vertex.
2. Add all edges from this vertex to a priority queue.
3. Repeatedly pick the **smallest-weight edge** that connects the tree to a new vertex.
4. Add the chosen vertex to the MST.
5. Add its outgoing edges into the priority queue.
6. Continue until all vertices are included.

---

## 🧩 Key Properties

* Produces a valid MST
* Works even if edge weights are equal
* Never forms cycles
* Greedy choices guarantee optimality
* Very efficient with a priority queue (heap)

---

## 🧩 Example Uses

* Laying out electrical wiring or fiber networks
* Constructing airline route networks
* Generating random mazes
* Choosing connections that minimize material/cost

---

## 📚 Additional Notes

* Similar to Kruskal’s, but Kruskal sorts edges globally;
  Prim grows from a **local frontier**.
* Prim’s is generally better for dense graphs, while Kruskal’s is often better for sparse graphs with DSU.

---

## 🏁 Summary

Prim’s Algorithm is a foundational greedy technique for computing a minimum spanning tree by expanding outward from a starting node using the smallest available edge. Its simplicity and efficiency make it ideal for a wide range of graph-based optimization problems.

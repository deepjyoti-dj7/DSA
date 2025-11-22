# Kruskal’s Algorithm

Kruskal’s Algorithm is a greedy algorithm used to find the **Minimum Spanning Tree (MST)** of a **connected, weighted, undirected graph**. It works by sorting edges and adding them one-by-one, ensuring that no cycles are formed.

---

## 🚀 What Is Kruskal’s Algorithm?

Kruskal’s algorithm answers:

**“What is the minimum-cost subset of edges that connects all vertices without forming cycles?”**

It works by selecting edges in increasing order of weight and adding them if they connect two **different** components.
To efficiently track components, it uses the **Disjoint Set Union (DSU)** / Union–Find structure.

---

## 🌟 Key Features

* Greedy algorithm
* Builds MST by selecting the **globally smallest edge**
* Uses **DSU** to detect cycles efficiently
* Works well for **sparse graphs**

---

## 🧠 When to Use Kruskal’s

Use Kruskal’s algorithm when:

* The graph is **sparse** (few edges)
* You have edge list representation
* You need a clear cycle-avoidance mechanism (DSU)
* Real-world use cases include:

  * Network design
  * Clustering
  * Reducing connections while preserving full reachability

---

## 📈 Time & Space Complexity

### With sorting and DSU:

* **Time Complexity:** `O(E log E)` or `O(E log V)`
  (Sorting edges dominates)
* **Space Complexity:** `O(V)` for DSU

---

## 🔍 How It Works (Conceptual Steps)

1. Sort all edges by **increasing weight**.
2. Initialize DSU (each node is its own component).
3. For each edge (u, v) in sorted order:

   * If u and v are in **different components**, add the edge to the MST
   * Union the two components using DSU
4. Stop when MST has **V – 1 edges**

Kruskal’s avoids cycles naturally through DSU.

---

## 🧩 Key Properties

* Produces an optimal MST
* Easy to implement
* Works well even with large number of edges
* Cycle-free guarantee via DSU
* Does **not** require graph connectivity—if disconnected, produces a **Minimum Spanning Forest**

---

## 🧩 Example Uses

* Building efficient road, pipeline, or electrical networks
* Image segmentation algorithms
* Clustering in machine learning
* Cable/utility layout optimization

---

## 📚 Additional Notes

* If the graph is dense, Prim’s may be more efficient
* If the graph is sparse, Kruskal’s is often the best choice
* Requires sorting edges, but DSU makes cycle detection extremely fast

---

## 🏁 Summary

Kruskal’s Algorithm constructs an MST by sorting edges and adding the smallest ones that do not create cycles. Combined with DSU, it is highly efficient, clean, and perfect for sparse graphs and global minimum-edge selection problems.

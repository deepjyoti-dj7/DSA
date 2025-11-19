# Topological Sort

Topological Sorting is an ordering of the nodes in a **directed acyclic graph (DAG)** such that for every directed edge `u → v`, node **u appears before v** in the ordering. It provides a linear sequence that respects all dependency directions in the graph.

---

## 🚀 What Is Topological Sorting?

Topological sort answers the question:
**“In what order can we process tasks so that all prerequisites come before the tasks that depend on them?”**

This only works on **DAGs** because cycles would make a valid ordering impossible.

---

## 🌟 Key Features

* Produces a **linear ordering** of vertices.
* Works **only on directed acyclic graphs (DAGs)**.
* Ensures all prerequisites appear before dependent tasks.
* Typically implemented using **DFS** or **in-degree + queue** (Kahn’s algorithm).

---

## 🧠 When to Use Topological Sort

Use topological sorting when dealing with:

* **Task scheduling with dependencies**
* **Build systems** (e.g., compiling modules in dependency order)
* **Course prerequisite ordering**
* **Pipeline processing**
* **Dependency resolution** (package managers, job order systems)

---

## 📈 Time & Space Complexity

For both common approaches (DFS-based and Kahn’s Algorithm):

* **Time Complexity**: `O(V + E)`
  Processes every node and edge once
* **Space Complexity**: `O(V)`
  Stores ordering + tracking structures

---

## 🔍 Two Common Approaches

### **1. DFS-Based Topological Sort**

* Perform DFS
* Add nodes to the ordering **after exploring all outgoing edges** (post-order)
* Reverse the collected order at the end

This relies heavily on the natural “backtracking” behavior of DFS.

---

### **2. Kahn’s Algorithm (In-degree Method)**

* Compute in-degree (number of incoming edges) for all nodes
* Push nodes with in-degree 0 into a queue
* Repeatedly remove from queue and decrease in-degree of neighbors
* Append nodes to the ordering as they are removed

If nodes remain with non-zero in-degree at the end → the graph has a cycle.

---

## 🧩 Example Uses

* Determining build order for software modules
* Scheduling lectures or courses based on prerequisites
* Ordering operations in data pipelines
* Resolving package installation order
* Dependency graphs in configuration systems

---

## 📚 Additional Notes

* Topological sort is **not unique**; multiple valid orders may exist.
* If a graph contains a **cycle**, no topological order exists.
* Often combined with DFS to detect cycles in directed graphs.

---

## 🏁 Summary

Topological sorting creates an ordering that respects all directed dependencies, making it indispensable for scheduling, planning, building, and reasoning about systems where some tasks must occur before others.

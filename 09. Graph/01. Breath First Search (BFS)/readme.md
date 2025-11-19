# Breadth-First Search (BFS)

Breadth-First Search (BFS) is a fundamental graph traversal algorithm used to explore nodes and edges of a graph in a systematic, level-by-level manner. It is commonly used to find the shortest path in unweighted graphs and serves as a backbone for many graph-based applications.

---

## 🚀 What Is BFS?

BFS starts at a chosen source node and visits all nodes at the current depth before moving to the next level. It explores the graph like waves spreading outward, ensuring that the shortest number of edges is used to reach any node for the first time.

---

## 🌟 Key Features

* **Level-order traversal**: Visits nodes in increasing distance from the source.
* **Shortest path guarantee**: Always finds the shortest path in an *unweighted* graph.
* **Uses a queue**: Ensures first-in-first-out order for exploring neighbors.
* **Avoids revisits**: Tracks visited nodes to prevent infinite loops.

---

## 🧠 When to Use BFS

Use BFS when you need:

* The **shortest path** in an unweighted graph
* **Connected components** in a graph
* **Level-by-level processing** (e.g., tree level-order traversal)
* To solve **grid-based problems** such as mazes
* To model **network broadcasts** or spreading processes

---

## 📈 Time & Space Complexity

* **Time Complexity**: `O(V + E)`
  Visits every vertex and edge once
* **Space Complexity**: `O(V)`
  Stores visited nodes and queue

---

## 🔍 BFS vs DFS

| BFS                                   | DFS                                |
| ------------------------------------- | ---------------------------------- |
| Level-by-level                        | Depth-first exploration            |
| Uses a queue                          | Uses a stack/recursion             |
| Guarantees shortest path (unweighted) | Does *not* guarantee shortest path |
| Higher memory usage                   | Lower memory usage                 |

---

## 🧩 Example Uses

* Finding the shortest path in grids and mazes
* Word ladder problems
* Social network analysis (e.g., degree of separation)
* Crawling websites
* Broadcasting in networks

---

## 📚 Additional Notes

BFS assumes all edges have equal weight. For weighted graphs where edges have different costs, use **Dijkstra's Algorithm** instead.

---

## 🏁 Summary

Breadth-First Search is one of the most powerful and intuitive traversal algorithms. Whether you are finding the shortest path, exploring graph structures, or modeling real-world systems, BFS provides a reliable, predictable, and efficient framework.

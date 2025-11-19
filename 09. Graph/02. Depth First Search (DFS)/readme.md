# Depth-First Search (DFS)

Depth-First Search (DFS) is a graph traversal algorithm that explores as far along a branch as possible before backtracking. It is ideal for exploring deep structures, detecting cycles, and solving problems that require exhaustive search.

---

## 🚀 What Is DFS?

DFS starts at a source node and explores one path fully before moving to the next. It behaves like following one hallway until it ends, then stepping back and trying another.

---

## 🌟 Key Features

* **Depth-first exploration**: Goes deep before exploring siblings.
* **Uses a stack conceptually**: Either an explicit stack or recursion.
* **Efficient memory usage**: Typically uses less memory than BFS.
* **Backtracking**: Core to its exploration strategy.

---

## 🧠 When to Use DFS

Use DFS when you need:

* To **explore all possible paths**
* **Cycle detection**
* **Topological sorting** of directed acyclic graphs
* Solving **puzzles** like mazes, backtracking problems
* Finding **connected components**
* Performing **tree traversals** (preorder, inorder, postorder)

---

## 📈 Time & Space Complexity

* **Time Complexity**: `O(V + E)`
  Visits every vertex and edge once
* **Space Complexity**:

  * `O(V)` in worst case (due to recursion/stack)
  * Often lower than BFS for wide graphs

---

## 🔍 DFS vs BFS

| DFS                                | BFS                                      |
| ---------------------------------- | ---------------------------------------- |
| Goes deep first                    | Explores level-by-level                  |
| Uses stack/recursion               | Uses queue                               |
| Does *not* guarantee shortest path | Guarantees shortest path (unweighted)    |
| Lower memory usage                 | Higher memory usage                      |
| Good for deep or exhaustive search | Good for shallow or shortest path search |

---

## 🧩 Example Uses

* Detecting cycles in graphs
* Topological sorting
* Solving backtracking problems (Sudoku, N-Queens, puzzles)
* Generating mazes
* Understanding graph structure
* Traversing trees

---

## 📚 Additional Notes

DFS is flexible because you can choose visiting order and implement it either recursively or iteratively. However, recursion depth may become an issue in very large graphs without tail-call optimization.

---

## 🏁 Summary

Depth-First Search excels at exploring deep or complex structures, detecting cycles, and solving problems that require full exploration or backtracking. Its simplicity, versatility, and low memory usage make DFS an essential algorithm in graph theory and computer science.

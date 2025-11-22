# Disjoint Set Union (DSU) / Union–Find

The **Disjoint Set Union (DSU)**, also known as the **Union–Find** data structure, is a powerful structure used to keep track of elements partitioned into a set of **disjoint (non-overlapping) subsets**. It efficiently supports two main operations:

* **Find**: Determine which set an element belongs to
* **Union**: Merge two sets together

DSU is widely used in algorithms that need to dynamically connect components while answering queries about component membership.

---

## 🚀 What Is DSU?

DSU maintains multiple groups where each element belongs to exactly one group.
You can quickly:

* Check if two elements are in the **same component**
* Merge the components containing two elements
* Track dynamic connectivity in a graph

---

## 🌟 Key Features

* Extremely fast operations (almost constant time)
* Simple but powerful design
* Optimized with:

  * **Path compression**
  * **Union by rank/size**

With these optimizations, operations run in **amortized O(α(n))**, where α is the inverse Ackermann function — effectively constant for all real-world inputs.

---

## 🧠 When to Use DSU

DSU is perfect for problems involving **connectivity**, **merging**, or **partitioning**:

* **Finding connected components** in graphs
* **Kruskal’s algorithm** for Minimum Spanning Tree
* Checking whether adding an edge creates a **cycle**
* Tracking **dynamic connectivity**
* Grouping items by constraints/similarity
* Offline queries (e.g., connectivity queries in reverse)

---

## 📈 Time & Space Complexity

### With path compression + union by rank:

* **Find**: ~O(1)
* **Union**: ~O(1)
* **Space**: O(n)

DSU is among the fastest data structures in practice.

---

## 🔍 Core Operations (Conceptually)

### **1. Find**

Returns the “representative” or “parent” of the set an element belongs to.

With **path compression**, we make future finds extremely fast by pointing nodes directly to their set representative.

---

### **2. Union**

Merges two sets by connecting the representative of one to the representative of the other.

To keep the structure balanced:

* **Union by rank**: always attach the shorter tree under the taller one
* **Union by size**: attach the smaller component to the larger one

Both keep the height low → ensures near-constant time operations.

---

## 🧩 Key Properties

* Elements form a forest of shallow trees
* Efficient even with millions of operations
* Path compression makes the structure almost flat
* Ensures nearly constant running time per operation
* Supports merging, grouping, and connectivity queries

---

## 🧩 Example Uses

* **Kruskal’s MST Algorithm**
* Detecting **cycles** in undirected graphs
* Tracking social network groups
* Grouping equivalent items (e.g., union of constraints)
* Solving dynamic connectivity problems
* Offline query solutions in competitive programming

---

## 📚 Additional Notes

* DSU does *not* support splitting sets once merged
* Ideal for problems where components only **grow**, not shrink
* DSU can be extended for:

  * Weighted unions
  * Tracking component sizes
  * Tracking additional metadata per component

---

## 🏁 Summary

The Disjoint Set Union / Union–Find data structure is one of the most efficient and elegant tools for managing dynamic, merging partitions. With path compression and union by rank/size, it operates in effectively constant time, making it indispensable for graph algorithms, connectivity problems, and competitive programming.

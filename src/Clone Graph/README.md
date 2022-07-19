# Clone Graph

## Question:

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

## How to Solve:

This problem can be solved by either DFS or BFS traversal, while
maintaining a hash map that maps the original node to the cloned node
(in C++, created with `new`). In general, BFS is slightly faster than
DFS in this problem, though DFS is easier to understand.

Let's start with the DFS approach:

### DFS

We write a helper DFS function that recursively tries to populate the
map with newly cloned nodes. The key point of this problem is
to remember to take of a cloned node's "neighbors" as well! This is
illustrated in the C++ implementation below.

### BFS

In the BFS approach, as usual, we maintain a FIFO queue and
iteratively try to exhaust the unvisited nodes. Again, do not forget
to take care of a newly cloned node's neighbors! You may also find the
BFS C++ implementation below.

## My C++ Solution:

### DFS

```cpp
class Solution {
 public:
  auto cloneGraph(Node *node) -> Node * {
    if (!node) return nullptr;

    return dfs(node);
  }

 private:
  unordered_map<Node *, Node *> umap;

  auto dfs(Node *node) -> Node * {
    if (umap.find(node) != umap.end()) return umap[node];

    umap[node] = new Node(node->val);

    for (auto *neighbor : node->neighbors) {
      umap[node]->neighbors.push_back(dfs(neighbor));
    }

    return umap[node];
  }
};
```

### BFS

```cpp
class Solution {
 public:
  auto cloneGraph(Node *node) -> Node * {
    if (!node) return nullptr;

    queue<Node *> q({node});  // for BFS
    umap[node] = new Node(node->val);

    while (!q.empty()) {
      auto *currNode = q.front();
      q.pop();

      for (auto *neighbor : currNode->neighbors) {
        if (umap.find(neighbor) == umap.end()) {
          umap[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }

        // NOTE: key line!
        umap[currNode]->neighbors.push_back(umap[neighbor]);
      }
    }
    return umap[node];
  }

 private:
  unordered_map<Node *, Node *> umap;  // original node, cloned node
};
```

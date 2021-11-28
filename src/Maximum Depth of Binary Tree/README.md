# Maximum Depth of Binary Tree

## Question:
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## How to Solve:

This problem simply tests the knowledge of recursion.

The base case is when the current position is `nullptr`, then we
return `0`. Otherwise, we return:

```cpp
return max(maxDepth(root->left), maxDepth(root->right)) + 1;
```

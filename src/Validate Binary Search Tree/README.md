# Valid Binary Search Tree

## Question:

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

## How to Solve:

The idea is to traverse the tree recursively, and set valid lower
bounds and upper bounds for the subtree calls. In the beginning, the
root's value can range from -infinity to +infinity. When we go left
into the root's left subtree, its valid range becomes -infinity to the
root's value. Similarly, the right subtree would have a valid range
from root's value to +infinity. We call the function recursively and
adjust the lower/upper bounds in each function call.

Since the node's values can range from `INT_MIN` to `INT_MAX`, we use
`LLONG_MIN` (long long min) and `LLONG_MAX` (long long max) as initial
ranges for the root.

## My C++ Solution:

```cpp
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
  }

 private:
  bool helper(TreeNode *root, long long lowerBound, long long upperBound) {
    if (!root) {
      return true;
    }
    if (root->val <= lowerBound || root->val >= upperBound) {
      return false;
    }
    return helper(root->left, lowerBound, root->val) && helper(root->right, root->val, upperBound);
  }
};
```
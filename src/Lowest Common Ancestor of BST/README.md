# Lowest Common Ancestor of a BST

## Question:

iven a binary search tree (BST), find the lowest common ancestor (LCA)
of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common
ancestor is defined between two nodes p and q as the lowest node in T
that has both p and q as descendants (where we allow a node to be a
descendant of itself).”


## How to Solve:

We use an iterative approach, starting node `curr` from `root`, each
time either moving it to `curr->left` or `curr->right`.

If the current node's value is smaller than both p and q's values, we
must advance current node to his right subtree. In the case where the
current node's value is greater than both p and q's values, we must
advance current node to his left subtree.

If neither case holds true, it means we have arrived at the "split
point", where `curr` is exactly the lowest common ancestor of p and q.

## My C++ Solution:

```cpp
class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto curr = root;
    while (curr) {
      if (curr->val < p->val && curr->val < q->val) {
        curr = curr->right;
      } else if (curr->val > p->val && curr->val > q->val) {
        curr = curr->left;
      } else {
        return curr;
      }
    }
    __builtin_unreachable();
  }
};
```
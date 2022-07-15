# Subtree of Another Tree

## Question:

Given the roots of two binary trees `root` and `subRoot`, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

## How to Solve:

We want to know that whether `t` is a subtree of `s`. Firstly, we
define a helper method to check whether two trees are the exact same
tree.

We recursively check whether `t` and `s` are the same tree, or if `t`
is a subtree of `s->left`, or if `t` is a subtree of `s->right`.

There are two important base cases: if `t` ever becomes `nullptr`,
then the function should return true. Or, if `s` ever becomes
`nullptr` then the function should return false (to the previous
level).

The way we define the helper function is also recursive. At each
recursive call, we check whether the 2 trees are both `nullptr`'s. If
so, then we return true. If only one of them is `nullptr`, then we
obviously return false. Then, we check whether values are the same. If
they are, we finally return the following recursive call (with a
logical AND):

```cpp
return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
```

## My C++ Solution:

```cpp
class Solution {
 public:
  bool isSubtree(TreeNode *s, TreeNode *t) {  // whether t is subtree of s
    if (!t) {
      return true;
    } else if (!s) {
      return false;
    } else {
      return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
  }

 private:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    } else if (!p || !q) {
      return false;
    } else if (p->val != q->val) {
      return false;
    } else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
};
```
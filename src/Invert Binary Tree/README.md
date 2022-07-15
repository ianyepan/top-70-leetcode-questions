# Invert Binary Tree

## Question:

Given the root of a binary tree, invert the tree (against the y-axis), and return its root.

## How to Solve:

We create a helper function `swapLR(root)` that takes in one TreeNode
argument and swaps the left subtree and right subtree of that
argument. It's a recursive function that calls `swapLR(root->left)`
and `swapLR(root->right)`, **before** actually swapping its left and
right children using the classic "`tmp=a; a=b; b=tmp`"
technique. Because we should start swapping the subtrees from bottom
up.

The base case is when `nullptr` is hit as root.

## My C++ Solution:

```cpp
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
  }
};
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    swapLR(root);
    return root;
  }

 private:
  void swapLR(TreeNode *root) {
    if (!root) {
      return;
    }
    swapLR(root->left);
    swapLR(root->right);
    TreeNode *tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
  }
};
```
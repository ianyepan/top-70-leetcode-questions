# Construct Binary Tree from Preorder and Inorder Traversal

## Question:

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

## How to Solve:

Given the preorder traversal vector, we have quick access to the tree
root, which is simply `preorder[0]`. If we know the root, then we can
look at the `inorder` vector and split it into two halves: the left
subtree and the right subtree. Then, we initialize the next element in
the `preorder` vector to be the new root to construct the subtree.

We also build a hashmap to store the "value-index" lookup for the
inorder vector, so later we can have O(1) access to the root
determined by `preorder`. We also keep a running index `p` to keep track
our position in the `preorder` array.

## My C++ Solution:

```cpp
class Solution {
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      inorderIndexMap[inorder[i]] = i;
    }
    return vectorToTree(preorder, 0, (int)preorder.size() - 1);
  }

 private:
  int p = 0;
  unordered_map<int, int> inorderIndexMap;  // value to index map
  TreeNode *vectorToTree(const vector<int> &preorder, int left, int right) {
    if (left > right) return nullptr; // range empty
    auto *root = new TreeNode(preorder[p]);
    ++p;
    root->left = vectorToTree(preorder, left, inorderIndexMap[root->val] - 1);
    root->right = vectorToTree(preorder, inorderIndexMap[root->val] + 1, right);
    return root;
  }
};
```
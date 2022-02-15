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

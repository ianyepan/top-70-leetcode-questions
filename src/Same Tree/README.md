# Same Tree

## Question:

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

## How to Solve:

This problem tests tree recursion. The function `isSameTree(p, q)`
should recursively call `isSameTree(p->left, q->left)` and
`isSameTree(p->right, q->right)` and make sure both are `true`. At
each level we check whether `p` and `q` are equal. The base case is
when one or both of them become `nullptr`.

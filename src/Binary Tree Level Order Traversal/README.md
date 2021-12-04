# Binary Tree Level Order Traversal


## Question:

Given the root of a binary tree, return the level order traversal of
its nodes' values. (i.e., from left to right, level by level).

## How to Solve:

This is a perfect problem to utilize BFS. We initialize a queue with
`root` in it. Then we do the classic BFS while loop (while the queue
is not empty):

- We would like to store all the current elements in the queue to some
  variable called `currLevel` of type vector. Because the current
  elements in the are all of the same level, and should together be
  pushed back as one vector element to our final answer (2D vector).

- When we process a node, we pop it and push both its children (if not
  null) to the back of the queue, we create the risk of messing up the
  "pureness" of all elements in the queue being from the same
  level. Which is why at the start of each while loop iteration, we
  need to pre-determine the current size of the queue, and "only pop
  this many times" for this iteration. This would guarantee that we
  only pop and process nodes of one level at each while loop
  iteration. Their children which we pushed to the back of the queue
  will be processed in the next while loop iteration.

# Spiral Matrix

## Question:

Given an m x n matrix, return all elements of the matrix in spiral
order. (See example graph on LeetCode for better visualization).

## How to Solve:

This question isn't tough per se -- it's just tedious to keep track of
the indices.

We initialize four variables respectively pointing to the row begin,
column begin, row end, and column end. The former two starts at zero
an increases, while the latter two starts at height-1 and width-1 and
decreases.

We then wrap four for-loops inside a big while-loop, each time
incrementing row being and column begin, while decreasing row end and
column end, until row begin surpasses row end, or column begin
surpasses column end.

Having this in mind, the code is rather self-explanatory.

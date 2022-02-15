# Rotate Image

## Question:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

## How to Solve:

An elegant way to rotate a matrix is to perform the following two
steps:

1. Reverse upside-down (reflect along the middle x-axis)
2. Reverse along the main diagonal

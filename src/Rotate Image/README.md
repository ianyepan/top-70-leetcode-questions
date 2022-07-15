# Rotate Image

## Question:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

## How to Solve:

An elegant way to rotate a matrix is to perform the following two
steps:

1. Reverse upside-down (reflect along the middle x-axis)
2. Reverse along the main diagonal

## My C++ Solution:

```cpp
class Solution {
 public:
  // Classic two-step approach
  void rotate(vector<vector<int>> &mat) {
    int n = mat.size();

    // 1. Upside-down row-wise swap
    for (int i = 0; i < n / 2; ++i) {
      swap(mat[i], mat[n - 1 - i]);
    }

    // 2. Mirror diagonal swap
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(mat[i][j], mat[j][i]);
      }
    }
  }
};
```
# Set Matrix Zeroes

## Question:
Given an m by n integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix. You must do it in place.

## How to Solve:

We use the leftmost column and the top row as temporary indicators of
whether the pointing row/column should be ultimately marked with
zeroes.

- Whether the leftmost column itself should be marked with zeroes is
  done as such:

    - We first maintain a variable to indicate whether the leftmost
    column should be marked as zeroes (by checking if the first column
    contains zeroes), but only actually mark them in the end (because we
    don't want the leftmost column to be tainted with zeroes.

- Whether the top row itself should be marked with zeroes is done as
  such:

  - We treat the top row as a normal part of the matrix, and
    also use the leftmost column as its indicator (specifically with
    `mat[0][0]`). But the row itself would serve as indicators for the
    rest of the bottom right matrix.

Then we check the rest of the matrix, and mark the indicators:

```c++
  mat[i][0] = 0; // entire row should be zeroes
  mat[0][j] = 0; // entire col should be zeroes
```
whenever we find that `mat[i][j]` is zero.

After the markings are done, we use the leftmost column and the top
row as indicators, and traverse the smaller matrix (without the leftmost
column and the top row) to correctly mark each entry. The code is
clear as follows:

```c++
  for (int i = 1; i < n; ++i)
  {
    for (int j = 1; j < m; ++j)
    {
      if (mat[i][0] == 0 || mat[0][j] == 0)
      {
        mat[i][j] = 0;
      }
    }
  }
```

Finally, we must deal with whether the leftmost column itself, and the
top row should be marked as all zeroes. If `mat[0][0]` is zero, then
the top row must be marked as zeroes. We then look at our variable in
the beginning, and decide whether to mark the entire leftmost column
as zeroes.

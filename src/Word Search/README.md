# Word Search

## Question:

Given an m x n grid of characters board and a string word, return true
if word exists in the grid.

The word can be constructed from letters of sequentially adjacent
cells, where adjacent cells are horizontally or vertically
neighboring. The same letter cell may not be used more than once.
 
## How to Solve:

This is a classic backtracking problem. We start a brand new
backtracking process at every cell, each time exploring (in DFS-style)
each of the four directions as deeply as possible. Within each
exploration, we mark the visited cells, but also unmark them when we
backtrack to try another path. Note that we only further backtrack
when the current cell matches the corresponding character in the
target word. The way we mark the visited cells is just to assign it
with any non-alphabetical character, so that in a deeper level it
would never equate with a character in the target word, and hence must
give up that branch of exploration.

## My C++ Solution:

```cpp
class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    this->board = board;
    this->word = word;
    m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (backtrack(i, j)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  vector<vector<char>> board{};
  string word{};
  int m{}, n{};
  bool backtrack(int i, int j, int idx = 0) {
    if (idx > word.length() - 1) {
      return true;
    }
    if (i < 0 || j < 0 || i >= m || j >= n || (board[i][j] != word[idx])) {
      return false;
    }
    // Matches!
    board[i][j] = '*';  // mark visited
    bool furtherBacktrack = backtrack(i + 1, j, idx + 1) || backtrack(i - 1, j, idx + 1) ||
                            backtrack(i, j + 1, idx + 1) || backtrack(i, j - 1, idx + 1);
    board[i][j] = word[idx];  // backtrack, unmark visited
    return furtherBacktrack;
  }
};
```
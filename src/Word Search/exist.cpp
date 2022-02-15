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

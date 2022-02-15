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

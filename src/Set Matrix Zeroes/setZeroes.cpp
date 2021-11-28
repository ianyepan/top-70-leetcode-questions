class Solution {
 public:
  void setZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    bool v = false;  // whether leftmost col should be zeroes
    for (int i = 0; i < n; ++i) {
      if (mat[i][0] == 0) {
        v = true;
      }
      for (int j = 1; j < m; ++j)  // col start with 1
      {
        if (mat[i][j] == 0) {
          mat[i][0] = 0;  // entire row should be zeroes
          mat[0][j] = 0;  // entire col should be zeroes
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (mat[i][0] == 0 || mat[0][j] == 0) {
          mat[i][j] = 0;
        }
      }
    }
    if (mat[0][0] == 0) {
      for (int j = 0; j < m; ++j) {
        mat[0][j] = 0;
      }
    }
    if (v) {
      for (int i = 0; i < n; ++i) {
        mat[i][0] = 0;
      }
    }
  }
};

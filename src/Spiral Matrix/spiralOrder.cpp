class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>> &mat) {
    if (mat.size() == 0) return {};
    // Initialize boundaries
    int row_begin = 0, row_end = mat.size() - 1;
    int col_begin = 0, col_end = mat[0].size() - 1;
    vector<int> ans;
    while (row_begin <= row_end && col_begin <= col_end) {
      for (int i = col_begin; i <= col_end; ++i) {
        ans.push_back(mat[row_begin][i]);
      }
      ++row_begin;

      for (int i = row_begin; i <= row_end; ++i) {
        ans.push_back(mat[i][col_end]);
      }
      --col_end;

      if (row_begin <= row_end) {  // still rows to traverse through
        for (int i = col_end; i >= col_begin; --i) {
          ans.push_back(mat[row_end][i]);
        }
        --row_end;
      }

      if (col_begin <= col_end) {  // still cols to traverse through
        for (int i = row_end; i >= row_begin; --i) {
          ans.push_back(mat[i][col_begin]);
        }
        ++col_begin;
      }
    }
    return ans;
  }
};

struct TupleHash {
  template <typename T1, typename T2>
  auto operator()(const tuple<T1, T2> &tup) const -> size_t {
    return hash<T1>{}(get<0>(tup)) ^ hash<T2>{}(get<1>(tup));
  }
};

class Solution {
 public:
  auto pacificAtlantic(const vector<vector<int>> &heights_) -> vector<vector<int>> {
    heights = heights_;
    ROWS = static_cast<int>(heights.size());
    COLS = static_cast<int>(heights[0].size());
    unordered_set<tuple<int, int>, TupleHash> pacific;
    unordered_set<tuple<int, int>, TupleHash> atlantic;
    for (int col = 0; col < COLS; ++col) {
      dfs(0, col, pacific, numeric_limits<int>::min());
      dfs(ROWS - 1, col, atlantic, numeric_limits<int>::min());
    }
    for (int row = 0; row < ROWS; ++row) {
      dfs(row, 0, pacific, numeric_limits<int>::min());
      dfs(row, COLS - 1, atlantic, numeric_limits<int>::min());
    }
    vector<vector<int>> res;
    for (int row = 0; row < ROWS; ++row) {
      for (int col = 0; col < COLS; ++col) {
        auto tup = make_tuple(row, col);
        if (pacific.find(tup) != pacific.end() && atlantic.find(tup) != atlantic.end()) {
          res.push_back({std::get<0>(tup), std::get<1>(tup)});
        }
      }
    }
    return res;
  }

 private:
  int ROWS;
  int COLS;
  vector<vector<int>> heights;
  void dfs(int row, int col, unordered_set<tuple<int, int>, TupleHash> &ocean, int prevHeight) {
    if (ocean.find({row, col}) != ocean.end() || row < 0 || row >= ROWS || col < 0 || col >= COLS ||
        heights[row][col] < prevHeight) {
      return;
    }
    ocean.insert({row, col});
    dfs(row + 1, col, ocean, heights[row][col]);
    dfs(row - 1, col, ocean, heights[row][col]);
    dfs(row, col + 1, ocean, heights[row][col]);
    dfs(row, col - 1, ocean, heights[row][col]);
  }
};

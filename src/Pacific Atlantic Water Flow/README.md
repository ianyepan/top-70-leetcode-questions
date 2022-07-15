# Pacific Atlantic Water Flow

## Question:

There is an `m x n` rectangular island that borders both the Pacific
Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left
and top edges, and the Atlantic Ocean touches the island's right and
bottom edges.

The island is partitioned into a grid of square cells. You are given
an `m x n` integer matrix heights where `heights[r][c]` represents the
height above sea level of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to
neighboring cells directly north, south, east, and west if the
neighboring cell's height is less than or equal to the current cell's
height. Water can flow from any cell adjacent to an ocean into the
ocean.

Return a 2D list of grid coordinates result where `result[i] = [ri,
ci]` denotes that rain water can flow from cell `(ri, ci)` to both the
Pacific and Atlantic oceans.

## How to Solve:

We start by creating two hash sets that will respectively hold
coordinate pairs that are reachable by Pacific or Atlantic ocean. In
the end, we'd take the intersection of these two sets as our returned result.

The key to solving this problem is, instead of starting at each cell
and checking if it can reach an ocean, we start at the ocean and
perform depth-first search, marking every cell along the way (by
storing it to the correct hash set), and stopping when the height
progression is no longer valid. Naturally, we should start the borders
and DFS inwards. In order for the DFS traversal to continue, the
heights must be "weakly ascending" -- we perform this by passing an
extra variable, `prevHeight`, into the deeper recursive call.

## My C++ Solution:

```cpp
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
```
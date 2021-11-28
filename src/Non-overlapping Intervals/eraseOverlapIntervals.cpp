class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = (int)intervals.size();
    if (n == 0) {
      return 0;
    }
    // Ascending sort by end-time
    sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) { return v1[1] < v2[1]; });
    vector<int> prev = intervals[0];
    int remove_count = 0;
    for (int i = 1; i < n; ++i) {
      vector<int> cur = intervals[i];
      if (prev[1] <= cur[0]) {
        prev = cur;
      } else {
        ++remove_count;
      }
    }
    return remove_count;
  }
};

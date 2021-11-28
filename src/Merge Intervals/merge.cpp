class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &v) {
    sort(v.begin(), v.end());  // sort by start-time (default)
    vector<vector<int>> merged;
    for (const auto &pair : v) {
      if (!merged.empty() && merged.back()[1] >= pair[0]) {
        merged.back()[1] = max(merged.back()[1], pair[1]);
      } else {
        merged.push_back(pair);
      }
    }
    return merged;
  }
};

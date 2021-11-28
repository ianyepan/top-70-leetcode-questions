// Linear scan (seemingly not optimized, but empirically faster)
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> ans;
    ans.reserve(intervals.size() + 1);
    for (auto &interval : intervals) {
      if (interval[0] <= newInterval[0]) {
        ans.push_back(interval);
      } else {
        break;
      }
    }
    if (ans.empty() || ans.back()[1] < newInterval[0]) {
      ans.push_back(newInterval);
    } else {
      ans.back()[1] = max(ans.back()[1], newInterval[1]);
    }
    for (auto &interval : intervals) {
      if (interval[0] <= newInterval[0]) {
        continue;
      }
      if (ans.back()[1] >= interval[0]) {
        ans.back()[1] = max(ans.back()[1], interval[1]);
      } else {
        ans.push_back(interval);
      }
    }
    return ans;
  }
};


// Binary Search (for some reason, it's actually slower)
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    int n = intervals.size();
    vector<vector<int>> ans;
    ans.reserve(n + 1);
    auto comp = [](auto &v1, auto &v2) { return v1[0] < v2[0]; };
    int pivot = upper_bound(begin(intervals), end(intervals), newInterval, comp) - begin(intervals);
    for (int i = 0; i < pivot; ++i) {
      if (intervals[i][0] <= newInterval[0]) {
        ans.push_back(intervals[i]);
      }
    }
    if (ans.empty() || ans.back()[1] < newInterval[0]) {
      ans.push_back(newInterval);
    } else {
      ans.back()[1] = max(ans.back()[1], newInterval[1]);
    }
    for (int i = pivot; i < n; ++i) {
      if (ans.back()[1] >= intervals[i][0]) {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      } else {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }
};

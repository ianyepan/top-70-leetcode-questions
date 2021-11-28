

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> ans;

    for (const auto &s : strs) {
      auto s_sorted = s;
      sort(s_sorted.begin(), s_sorted.end());
      m[s_sorted].push_back(s);
    }

    for (const auto &elem : m) {
      ans.push_back(elem.second);
    }

    return ans;
  }
};

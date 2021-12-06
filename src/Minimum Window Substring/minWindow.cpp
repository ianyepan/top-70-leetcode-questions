// Hash map solution
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> tMap;
    for (auto ch : t) {
      ++tMap[ch];
    }
    int l = 0, r = 0;
    int required = tMap.size(), satisfied = 0;
    unordered_map<char, int> windowMap;
    vector<int> ans{INT_MAX, l};
    const int n = s.length();
    for (r = 0; r < n; ++r) {
      ++windowMap[s[r]];
      if (tMap.find(s[r]) != tMap.end() && windowMap[s[r]] == tMap[s[r]]) {
        ++satisfied;
      }
      // Try to shrink on the left side, see if we can get a smaller
      // satisfying substring.
      while (l <= r && satisfied == required) {
        if (ans[0] == -1 || r - l + 1 < ans[0]) {
          ans[0] = r - l + 1;
          ans[1] = l;
        }
        cout << s[l] << " " << windowMap[s[l]] << "\n";
        --windowMap[s[l]];
        if (tMap.find(s[l]) != tMap.end() && windowMap[s[l]] < tMap[s[l]]) {
          --satisfied;
          ++l;
          break;
        } else {
          ++l;
        }
      }
    }
    return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
  }
};

// Same solution, except using vectors
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> tMap(128, 0);
    for (auto ch : t) {
      ++tMap[ch];
    }
    int l = 0, r = 0;
    int required = unordered_set<char>(begin(t), end(t)).size(), satisfied = 0;
    vector<int> windowMap(128, 0);
    vector<int> ans{INT_MAX, l};
    const int n = s.length();
    for (r = 0; r < n; ++r) {
      ++windowMap[s[r]];
      if (tMap[s[r]] != 0 && windowMap[s[r]] == tMap[s[r]]) {
        ++satisfied;
      }
      // Try to shrink on the left side, see if we can get a smaller
      // satisfying substring.
      while (l <= r && satisfied == required) {
        if (ans[0] == -1 || r - l + 1 < ans[0]) {
          ans[0] = r - l + 1;
          ans[1] = l;
        }
        --windowMap[s[l]];
        if (tMap[s[l]] != 0 && windowMap[s[l]] < tMap[s[l]]) {
          --satisfied;
          ++l;
          break;
        } else {
          ++l;
        }
      }
    }
    return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
  }
};

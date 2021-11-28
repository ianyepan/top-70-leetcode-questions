class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    } else if (seen.find(n) != seen.end()) {
      return seen[n];
    }
    seen[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return seen[n];
  }

 private:
  unordered_map<int, int> seen;
};

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = (int)prices.size();
    if (n < 2) {
      return 0;
    }
    int curr_min = prices[0];
    int curr_max_profit = 0;
    for (int i = 1; i < n; ++i) {
      curr_min = min(curr_min, prices[i]);
      curr_max_profit = max(curr_max_profit, prices[i] - curr_min);
    }
    return curr_max_profit;
  }
};

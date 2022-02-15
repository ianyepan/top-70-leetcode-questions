#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    for (const auto num : nums) {
      ++umap[num];
    }
    auto comp = [](auto p1, auto p2) { return p1.second > p2.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);  // min heap
    vector<int> ans;
    for (const auto [val, freq] : umap) {
      pq.push({val, freq});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    for (int i = 0; i < k; ++i) {
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};

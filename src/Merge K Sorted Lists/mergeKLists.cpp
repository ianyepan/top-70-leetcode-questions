class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto comp = [](const auto &p1, const auto &p2) { return p1.first > p2.first; };
    using HeapNode = pair<int, ListNode *>;
    priority_queue<HeapNode, vector<HeapNode>, decltype(comp)> pq(comp);
    for (const auto node : lists) {
      if (node) {
        pq.push({node->val, node});
      }
    }
    auto sentinel = make_unique<ListNode>();
    auto curr = sentinel.get();
    while (!pq.empty()) {
      auto [_, topNode] = pq.top();
      pq.pop();
      curr->next = topNode;
      curr = curr->next;
      topNode = topNode->next;
      if (topNode) {
        pq.push({topNode->val, topNode});
      }
    }
    return sentinel->next;
  }
};

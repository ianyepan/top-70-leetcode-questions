# Merge K Sorted Lists

## Question:

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

## How to Solve:

We maintain a size-k min heap (with priority queue) that keeps track
the current heads pointing to each of the k lists. At each iteration,
we pop the list head that has the smallest value and append it to our
answer, which is initialized as a sentinel node. When a list head is
popped, we push the next node of its list back to our min heap and
proceed to the next iteration.

Note that we will return `sentinel->next` as the last statement, and
since `sentinel` should be "deleted" by the end of the function to
avoid memory leak, we can use modern C++'s `unique_ptr` to initialize
our sentinel node. Here is a common pattern to avoid memory leaks with
`new` and forgetting to `delete`:

```cpp
auto sentinel = make_unique<ListNode>();
auto curr = sentinel.get();
// ...
return sentinel->next;
```

## My C++ Solution:

```cpp
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
```
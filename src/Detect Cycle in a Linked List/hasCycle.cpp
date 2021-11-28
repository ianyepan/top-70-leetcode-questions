#include <iterator>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {
  }
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *slow_ptr = head, *fast_ptr = head;
    while (fast_ptr && fast_ptr->next) {
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;

      // Compare slow_ptr and fast_ptr after at least 1 update
      if (slow_ptr == fast_ptr) {
        return true;
      }
    }
    return false;
  }
};

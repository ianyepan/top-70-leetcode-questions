class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto sentinel = make_unique<ListNode>(0, head);
    auto ptr1 = sentinel.get(), ptr2 = sentinel.get();
    for (int i = 0; i <= n; ++i) {
      ptr1 = ptr1->next;
    }
    while (ptr1) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    ptr2->next = ptr2->next->next;
    return sentinel->next;
  }
};

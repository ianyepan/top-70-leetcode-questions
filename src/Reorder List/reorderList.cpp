struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }
};
class Solution {
 public:
  void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
      return;
    }
    ListNode *slow = head, *fast = head, *head1 = head;
    ListNode *head2, *tmp1, *tmp2;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    head2 = slow->next;
    slow->next = nullptr;        // split list in half
    head2 = reverseList(head2);  // reverse 2nd half
    while (head1 && head2) {
      tmp1 = head1->next;
      tmp2 = head2->next;
      head1->next = head2;
      head2->next = tmp1;
      head1 = tmp1;
      head2 = tmp2;
    }
  }

 private:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev_ = nullptr;
    ListNode *curr_ = head;
    ListNode *next_;
    while (curr_) {
      next_ = curr_->next;
      curr_->next = prev_;
      prev_ = curr_;
      curr_ = next_;
    }
    return prev_;
  }
};

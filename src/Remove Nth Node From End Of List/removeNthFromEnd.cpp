struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr)
  {
  }
  ListNode(int x) : val(x), next(nullptr)
  {
  }
  ListNode(int x, ListNode *next) : val(x), next(next)
  {
  }
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummy_ptr = new ListNode(0, head);
    ListNode *ptr1 = dummy_ptr, *ptr2 = dummy_ptr;

    for (int i = 0; i <= n; ++i)
    {
      ptr1 = ptr1->next;
    }

    while (ptr1)
    {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }

    ptr2->next = ptr2->next->next;
    return dummy_ptr->next;
  }
};

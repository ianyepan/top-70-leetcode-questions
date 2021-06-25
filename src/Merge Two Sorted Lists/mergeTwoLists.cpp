#include <cstddef>
#include <iterator>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL)
  {
  }
};

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *curr = &dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        curr->next = l1;
        l1 = l1->next;
      }
      else
      {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }

    if (l1)
    {
      curr->next = l1;
    }
    else if (l2)
    {
      curr->next = l2;
    }

    return dummy.next;
  }
};

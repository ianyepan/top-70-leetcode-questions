# Linked List Cycle

## Question:

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list
that can be reached again by continuously following the `next`
pointer. Internally, `pos` is used to denote the index of the node
that tail's next pointer is connected to. **Note that `pos` is not
passed as a parameter.**

_Return true if there is a cycle in the linked list. Otherwise, return
false._

## How to Solve:

### Method 1

This solution requires a 2-pointer technique: a slow pointer, and a
fast pointer. We iterate the linked list with a while loop, until
either the fast pointer or fast pointer's next reaches the end
(i.e. `nullptr`). After time, the slow pointer advances by one node,
but the fast pointer advances by two nodes (double the speed!). If
there is a cycle in the linked list, it is guaranteed that the fast
pointer will catch up with the slow pointer (from behind). Why?
Because in terms of "relative velocity", the fast pointer is simply
approaching the slow pointer one node at a time.

The code for this method is in `hasCycle.cpp`.

### Method 2

The second solution is slightly slower and uses more space. However,
it's more straightforward.

We maintain a set of pointers that we've seen so far. Before we reach
the end of the linked list (if there is one), if we see the same
pointer again that was already stored in the `seen` set, we return
`true`. If we successfully reach the end (`nullptr`), then we return
`false`.

Code as follows:

```cpp
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    unordered_set<ListNode *> seen;
    ListNode *curr = head;
    while (curr)
    {
      if (seen.find(curr) == seen.end())
      {
        seen.insert(curr);
        curr = curr->next;
      }
      else
      {
        return true;
      }
    }
    return false;
  }
};
```

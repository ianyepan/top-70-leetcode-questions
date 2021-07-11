# Reorder List

## Question:

You are given the head of a singly linked-list. The list can be represented as:

`L0 → L1 → … → Ln - 1 → Ln`

Reorder the list to be on the following form:

`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → ...`

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

## How to Solve:

The main idea is to split the list in half (into 2 lists), reverse the
second half, and we use a 6-statement technique to "weave" (merge) the
two lists together.

### Splitting the list in half

We use 2 pointers, a `slow` and a `fast`, and advance `slow` to next
one a time, while advancing `fast` to next's next each time, with
twice the speed. When `fast` has reached the end of the list, `slow`
must be in the middle of the original list, ready to be
split. `slow->next` would be our second list's new head.

### Reversing the second half

Reversing a linked list is a classic problem that is discussed
[here](https://www.youtube.com/watch?v=O0By4Zq0OFc). The main idea is
to use three pointers (`prev`, `curr`, `next`) to collaboratively
traverse the list only once yet being able to reverse the list
starting from changing the head to the tail. At each step, `prev`,
`curr`, and `next` are roughly in such left-to-right pointer
positions.

### Weaving (Merging) two lists together

The technique is as follows:

```cpp
  while (head1 && head2)
  {
    tmp1 = head1->next;
    tmp2 = head2->next;

    head1->next = head2;
    head2->next = tmp1;

    head1 = tmp1;
    head2 = tmp2;
  }
```

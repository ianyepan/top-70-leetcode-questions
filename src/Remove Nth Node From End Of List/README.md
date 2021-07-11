# Remove Nth Node From End of List

## Question:

Given the head of a linked list, remove the nth node from the end of
the list and return its head.

## How to Solve:

The first approach (`O(2n)`) is to find the length (size) of the
linked list first we a single pass. Then we locate the node to remove
by going again from the start to `size - n - 1`. We reroute the node's
next to next's next, and return head.

The second approach (`O(1n)`) is an optimized version of the first,
and requires only one pass in total. We maintain two pointers moving
at the same speed except with different head-starts. The first one
starts at the nth nodes from the start, and the second one starts
normally at the beginning of the list. When the first pointer reaches
the end, the second one must land on the node to remove (i.e. the nth
node from the end), since we have maintained the same distance between
the two pointers all along. The tricky thing about this approach is
that we need to create a dummy pointer that points to head, because we
might need to remove the head node. We need the 2 pointers to start
"one step before" the head.

The code implementation executes the second approach.

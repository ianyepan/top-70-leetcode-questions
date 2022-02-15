# Top K Frequent Elements

## Question:

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

## How to Solve:

This is a popular interview question. The classic method to solve this
is to maintain a size-K min heap (priority queue). When we add a new
element and the heap size exceeds K, we pop the top element (which is
the minimum element in terms of frequency). This way, we maintain that
the heap holds the top K most frequent element.

This method has a runtime of O(n log k). If we were to sort it, we
would spend O(n log n).

_Rule of thumb: when asked to find top K elements, we often use a
size-K MIN heap. When asked to find least K elements, we would use a
size-K MAX heap._

In C++, the default priority queue is implemented as a max heap. In
competitive programming, people often use a "hack" -- that is, negate
the number's sign and push it into the heap to simulate min
heap. Later, when retrieving it, we only need to negate it back.

In my code, I show the "standard/proper" way of implementing a min
heap with priority queue. First, I define a lambda function that
compares two pairs based on their second element. Then, I provide two
additional template argument to priority queue: one simply being a
vector of the element's type, another one being a "decltype" of the
lambda I defined. Finally, I pass the functor to the constructor on
the R.H.S. as well. Putting this together, we have:

```cpp
auto comp = [](auto p1, auto p2) { return p1.second > p2.second; };
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);  // min heap
```

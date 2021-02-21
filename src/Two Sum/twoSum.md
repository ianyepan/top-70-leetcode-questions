# Two Sum

## Question:

Given an array of integers `nums` and an integer `target`, return
indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and
you may not use the same element twice.

You can return the answer in any order.


## How to Solve:

Maintain a hash map (`unordered_map` in C++) that at every iteration records the difference between the target and the current number as key, and the current number's index as the value.

Whenever we encounter a current number that matches an existing key in the hash map, we know a pair of two-sum has been found. Then, we can return the existing key's matching value (which is the index of the first number of the two-sum) and the current index (the index of the second number of the two-sum).

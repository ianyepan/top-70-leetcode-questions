# Contains Duplicate

## Question:

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice
in the array, and it should return false if every element is distinct.


## How to Solve:

Transform the array into a set (`unordered_set` in C++), which takes
care of removing duplicates "automagically"! Then, we just have to
compare the size of the original array and our new set.

The syntax for creating a set out of a vector is as follows:

```cpp
std::unordered_set<type> mySet(myVector.begin(), myVector.end());
```

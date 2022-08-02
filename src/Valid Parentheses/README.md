# Valid Parentheses

## Question:

Given a string s containing just the characters `'(', ')', '{', '}', '['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.

## How to Solve:

We create a stack (`stack<char>` in C++) as our main data
structure. Whenever we encounter an opening bracket of any type, we
push it to the stack. When we encounter a closing bracket of any type,
we check whether the stack is empty, or if the stack's top (the one
most recently pushed in) is a match to our current closing bracket. If
either one of these 2 condition is false, then the string must not be
valid. If both condition passes, we simply pop the stack's top, and
proceed to reading the next character.

In the end, we check if the stack is empty.

## My C++ Solution:

```cpp
class Solution {
 public:
  auto isValid(const string &s) -> bool {
    for (const auto ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        parentheses_stack.push(ch);
        continue;
      }

      if (parentheses_stack.empty() ||
          parentheses_stack.top() != parentheses_map.at(ch)) {
        return false;
      }

      parentheses_stack.pop();
    }

    return parentheses_stack.empty();
  }

 private:
  const unordered_map<char, char> parentheses_map{
      {')', '('},
      {']', '['},
      {'}', '{'},
  };
  stack<char> parentheses_stack;
};
```

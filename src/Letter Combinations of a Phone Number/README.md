# Letter Combinations of a Phone Number

## Question:
Given a string containing digits from 2 to 9 inclusive, return all
possible letter combinations that the number could represent. Return
the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is
given below. Note that 1 does not map to any letters.

P.s. View original problem description page on LeetCode for the
figure.

## How to Solve:

The main body of the function is a triple-for-loop. [This discussion
thread](https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8090/Iterative-c%2B%2B-solution-in-0ms)
sums the idea up really well.

The method is best understood by and example. Copy-pasting directly
from the discussion thread, here's an intuitive example:

### Explanation with sample input "123"

#### Initial state:

- answer = {""}

#### Stage 1 for number "1":

- answer has {""}
- letters are "abc"
- generate three strings "" + "a", ""+"b", ""+"c" and put into buffer,
- buffer = {"a", "b", "c"}
- swap answer and buffer (swap does not take memory copy)
- Now answer has {"a", "b", "c"}

#### Stage 2 for number "2":

- answer has {"a", "b", "c"}
- letters are "def"
- generate nine strings and put into buffer,
  "a"+"d", "a"+"e", "a"+"f",
  "b"+"d", "b"+"e", "b"+"f",
  "c"+"d", "c"+"e", "c"+"f"
- so buffer has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
- swap answer and buffer
- Now answer has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }

#### Stage 3 for number "3":

- answer has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
- letters are "ghi"
- generate 27 strings and put into buffer,
  - add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd",
    "ce", "cf"
  - add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd",
    "ce", "cf"
  - add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd",
    "ce", "cf"
- so, buffer has
 {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
 "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
 "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi"}
- swap answer and buffer
- Now answer has
 {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
 "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
 "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi"}

#### Finally, return answer.

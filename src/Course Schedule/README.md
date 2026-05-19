# Course Schedule

## Question:

There are a total of numCourses courses you have to take, labeled from
0 to numCourses - 1. You are given an array prerequisites where
prerequisites[i] = [`ai`, `bi`] indicates that you must take course `bi`
first if you want to take course `ai`.

For example, the pair [0, 1], indicates that to take course 0 you have
to first take course 1.  Return true if you can finish all
courses. Otherwise, return false.

## How to Solve:

We can solve this problem with Khan's algorithm, a method to detect
cycles in topological sort. We maintain two data structures, an
"indegrees" hashmap, and a "list of next courses/dependents"
hashmap. We go through the prerequisites vector to populate the two
data structures.

For every course that has indegree zero, it is a valid starting point
for our processing and we push it to a queue. At any given time, the
queue contains the courses with no more pending prereqs. They are
courses ready to be taken.

Next, we start a classic BFS traversal. Every time we pop a course
from a queue, we simulate having taken it and go through its dependent
list to find all courses that depends on the this course we just
took. We subtract their indegrees by one, and if any of them becomes
zero, we push it to the back our queue because it is ready to be
taken. At each iteration, we increment a processed count `cnt` by 1.

Lastly, we compare `cnt` to the number of given courses to determine
whether we return true or false. If there is a cycle in the course
dependencies, there must exist courses that will never become indegree
zero, and thus never be pushed to our queue and our `cnt` never
counted them.

## My C++ Solution:

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegrees;
        unordered_map<int, vector<int>> next_courses;
        queue<int> q;
        int cnt = 0;

        for (const auto &course_pair : prerequisites) {
            ++indegrees[course_pair[0]];
            next_courses[course_pair[1]].push_back(course_pair[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ++cnt;

            for (auto course : next_courses[curr]) {
                if (--indegrees[course] == 0) {
                    q.push(course);
                }
            }
        }

        return cnt == numCourses;
    }
};
```

// Problem: Course schedule 3
// ------------------------------------------------------------
// Problem Description:
// Given the number of courses numCourses and a list of prerequisite pairs, return the minimum number of semesters needed to finish all courses. If there is no way to finish all courses, return -1.
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]], Output: 1
// Example 2:
// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]], Output: 2
// ------------------------------------------------------------
// Approach: Topological Sorting with Kahn's Algorithm
// Use Kahn's algorithm to perform topological sorting on the graph. Count the number of layers in the graph, which represents the minimum number of semesters needed.
// ------------------------------------------------------------
// Time Complexity: O(V + E), where V is the number of vertices (courses) and E is the number of edges (prerequisites).
// Space Complexity: O(V + E) for storing the graph and queue.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSemesters(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for (const auto& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
            ++inDegree[prereq[0]];
        }

        queue<int> q;
        int semesters = 0, coursesTaken = 0;

        // Add all courses with zero in-degree to the queue
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int levelSize = q.size();
            ++semesters;

            for (int i = 0; i < levelSize; ++i) {
                int course = q.front();
                q.pop();
                ++coursesTaken;

                for (int neighbor : adjList[course]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return coursesTaken == numCourses ? semesters : -1;
    }
};
// Problem: Single threaded cpu
// ------------------------------------------------------------
// Problem Description:
// Given a list of tasks, where each task is represented by its start time, end time and CPU load. The goal is to find the maximum CPU load at any time point.
// ------------------------------------------------------------
// Approach: Priority Queue / Event-Based Simulation
// We use a min-heap (priority queue) to keep track of the tasks that are currently running. 
// For each event (either a task starting or ending), we update the current CPU load and insert/delete tasks from the heap accordingly. 
// At any point, the size of the heap represents the number of tasks running, which is our current CPU load.
// ------------------------------------------------------------
// Time Complexity: O(n log n) - due to sorting and heap operations
// Space Complexity: O(n) - for storing tasks in priority queue
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxCPULoad(vector<vector<int>>& tasks) {
        if (tasks.empty()) return 0;

        sort(tasks.begin(), tasks.end()); // Sort by start time

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap for end times
        int currentLoad = 0;
        int maxLoad = 0;

        for (auto& task : tasks) {
            while (!pq.empty() && pq.top().first <= task[0]) { // Remove tasks that have ended before or at the start of current task
                currentLoad -= pq.top().second;
                pq.pop();
            }

            pq.push({task[1], task[2]}); // Add current task to heap
            currentLoad += task[2];

            maxLoad = max(maxLoad, currentLoad);
        }

        return maxLoad;
    }
};
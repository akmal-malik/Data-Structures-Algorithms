// Problem: Maximum profit in job scheduling
// ------------------------------------------------------------
// Problem Description:
// Given an array of jobs where each job has a start time, finish time, and profit.
// The goal is to find the maximum profit that can be achieved by non-overlapping jobs.
// ------------------------------------------------------------

// Approach: Dynamic Programming with Binary Search
// We sort jobs based on their finish times. Then, we use dynamic programming to keep track of the maximum profit up to each job.
// For each job, we use binary search to find the latest non-conflicting job and update the dp array accordingly.
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        vector<int> dp(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            int last = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i-1][0],
                                  [](int s, const auto& job){ return s < job[1]; }) - jobs.begin();
            
            dp[i] = max(dp[i-1], dp[last] + jobs[i-1][2]);
        }
        
        return dp[n];
    }
};
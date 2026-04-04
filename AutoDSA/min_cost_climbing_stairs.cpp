// Problem: Min cost climbing stairs
// ------------------------------------------------------------
// Problem Description:
// You are given an array cost[] consisting of N integers where cost[i] represents the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps. You need to find the minimum cost to reach the top of the floor.
// Note that the first step is always free.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use dynamic programming to solve this problem. We maintain an array dp[] where dp[i] represents the minimum cost to reach step i. The relation between states is given by:
// dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
// This gives us the minimum cost to reach each step.
// ------------------------------------------------------------
// Time Complexity: O(N)
// Space Complexity: O(N)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
};
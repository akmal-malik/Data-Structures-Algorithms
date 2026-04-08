// Problem: Min path sum
// ------------------------------------------------------------

// Problem Description:
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use dynamic programming to solve this problem. We create a 2D vector dp where dp[i][j] represents the minimum path sum from the top left corner to cell (i, j). For each cell, the minimum path sum is either the path sum from the cell above it plus the current cell's value or the path sum from the cell to the left of it plus the current cell's value. The base case is dp[0][0] which is simply grid[0][0].

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};
// Problem: Unique paths 2
// ------------------------------------------------------------
// Problem Description:
// Given a grid where each cell can either be empty (0) or blocked (1), 
// return the number of unique paths from the top-left corner to the bottom-right corner. 
// You can only move either down or right at any point in time.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use a 2D DP array where dp[i][j] represents the number of unique paths to cell (i, j). 
// Initialize the first row and column with 1s since there is only one way to reach cells on the border. 
// For other cells, if it's not blocked (grid[i][j] == 0), calculate dp[i][j] as the sum of paths from the cell above (dp[i-1][j]) and the cell to the left (dp[i][j-1]). If it's blocked, set dp[i][j] to 0.
// ------------------------------------------------------------
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the first column
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) dp[i][0] = 1;
        
        // Initialize the first row
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) dp[0][j] = 1;
        
        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
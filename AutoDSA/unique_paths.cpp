// Problem: Unique paths
// ------------------------------------------------------------
// Problem Description:
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use a 2D DP table where dp[i][j] represents the number of unique paths to reach cell (i, j).
// The robot can only come from either top (dp[i-1][j]) or left (dp[i][j-1]).
// Therefore, dp[i][j] = dp[i-1][j] + dp[i][j-1].
// Initialize the first row and first column to 1 since there's only one way to reach any cell in the first row or first column.
// ------------------------------------------------------------
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the first row and first column to 1
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        
        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
// Problem: Cherry pickup
// ------------------------------------------------------------

// Problem Description:
// Given a grid where each cell contains either 0 or 1, and two people starting at the same point in opposite corners, find the maximum number of cherries they can collect by moving towards each other simultaneously. They can only move right or down.
// ------------------------------------------------------------

// Approach: Dynamic Programming
// Use a DP table to store the maximum cherries collected up to each cell for both paths. The state dp[r1][c1][c2] represents the maximum cherries collected when one person is at (r1, c1) and the other is at (r1 + r2 - c1, c2).
// ------------------------------------------------------------
// Time Complexity: O(n^3)
// Space Complexity: O(n^3)
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        function<int(int, int, int)> dfs = [&](int r1, int c1, int c2) -> int {
            int r2 = r1 + c1 - c2;
            if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1;
            if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
            
            int cherries = grid[r1][c1];
            if (r1 != r2 || c1 != c2) {
                cherries += grid[r2][c2];
            }
            
            if (r1 == n-1 && c1 == n-1) return cherries;
            
            int maxCherries = -1;
            maxCherries = max(maxCherries, dfs(r1+1, c1, c2+1));
            maxCherries = max(maxCherries, dfs(r1, c1+1, c2+1));
            maxCherries = max(maxCherries, dfs(r1+1, c1, c2));
            maxCherries = max(maxCherries, dfs(r1, c1+1, c2));
            
            return dp[r1][c1][c2] = (maxCherries == -1) ? -1 : cherries + maxCherries;
        };
        
        return max(0, dfs(0, 0, 0));
    }
};
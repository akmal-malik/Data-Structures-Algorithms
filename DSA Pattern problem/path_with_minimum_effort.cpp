// Problem: Path with minimum effort
// ------------------------------------------------------------
// Problem Description:
// Given a 2D array heights where heights[i][j] represents the height of cell (i, j), 
// return the minimum effort path from top-left to bottom-right.
// You can only move either down or right at any point in time.
// The effort cost is the maximum absolute difference in heights between two consecutive cells in the path.
// ------------------------------------------------------------
// Approach: Dijkstra's Algorithm
// Use a min-heap priority queue to always expand the least effort path first. 
// Track visited cells and update the minimum effort required to reach each cell.
// ------------------------------------------------------------
// Time Complexity: O(m * n * log(m * n))
// Space Complexity: O(m * n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effortTo(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        effortTo[0][0] = 0;
        pq.push({0, {0, 0}});
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
        
        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();
            
            int x = pos.first, y = pos.second;
            
            if (x == m - 1 && y == n - 1) return effort;
            
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                int new_effort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                
                if (new_effort < effortTo[nx][ny]) {
                    effortTo[nx][ny] = new_effort;
                    pq.push({new_effort, {nx, ny}});
                }
            }
        }
        
        return -1; // This line should never be reached
    }
};
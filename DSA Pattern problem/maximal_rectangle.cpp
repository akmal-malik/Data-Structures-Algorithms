// Problem: Maximal rectangle
// ------------------------------------------------------------
// Problem Description:
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
// containing only 1's and return its area.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use a dynamic programming array to store the height of consecutive 1's up to 
// the current position for each column. Then, for each row, treat the histogram 
// represented by the height array and find the largest rectangle in the histogram.
// ------------------------------------------------------------
// Time Complexity: O(m * n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0); // To handle the last rectangle
        stack<int> s;
        int maxArea = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int h = height[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }

        return maxArea;
    }
};
// Problem: Pascal's triangle
// ------------------------------------------------------------
// Problem Description:
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
// The first and last numbers in each row are always 1.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use a 2D vector to store the Pascal's triangle. Each element is calculated as the sum of the two elements directly above it.
// Time Complexity: O(numRows^2)
// Space Complexity: O(numRows^2)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for (int i = 0; i < numRows; ++i) {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};
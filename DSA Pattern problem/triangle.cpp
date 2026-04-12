// Problem: Triangle
// ------------------------------------------------------------
// Problem Description:
// Given a triangle array, return the minimum path sum from top to bottom.
// At each step, you may move to adjacent numbers on the row below.
// ------------------------------------------------------------
// Approach: Dynamic Programming Bottom-Up
// We will use dynamic programming to solve this problem. 
// Starting from the second last row of the triangle, we will iterate upwards.
// For each element in the current row, we will update it by adding the minimum
// of the two adjacent elements in the row below. This way, by the time we reach
// the top of the triangle, the top element will contain the minimum path sum.
// ------------------------------------------------------------
// Time Complexity: O(n^2), where n is the number of rows in the triangle.
// Space Complexity: O(1), as we are modifying the input array in place.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
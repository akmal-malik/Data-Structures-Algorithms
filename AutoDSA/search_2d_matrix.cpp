// Problem: Search 2D Matrix
// ------------------------------------------------------------
// Problem Description:
// Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:
// - Integers in each row are sorted from left to right.
// - The first integer of each row is greater than the last integer of the previous row.
// ------------------------------------------------------------
// Approach: Binary Search
// Utilize binary search on the 2D matrix by treating it as a single sorted array. Calculate the middle element's position in the 2D matrix and compare it with the target.
// ------------------------------------------------------------
// Time Complexity: O(log(m * n))
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n];
            
            if (midValue == target) return true;
            else if (midValue < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return false;
    }
};
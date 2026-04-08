// Problem: Kth smallest in sorted matrix
// ------------------------------------------------------------
// Problem Description:
// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
// ------------------------------------------------------------
// Approach: Binary Search
// Perform binary search on the range of possible values (minimum element in the matrix to maximum element in the matrix) and use a helper function to count the number of elements less than or equal to a given value.
// ------------------------------------------------------------
// Time Complexity: O(n * log(max-min))
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int minVal = matrix[0][0], maxVal = matrix[n-1][n-1];
        while (minVal < maxVal) {
            int mid = minVal + (maxVal - minVal) / 2;
            if (countLessEqual(matrix, mid) < k) {
                minVal = mid + 1;
            } else {
                maxVal = mid;
            }
        }
        return minVal;
    }
private:
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int n = matrix.size();
        int row = n - 1, col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};
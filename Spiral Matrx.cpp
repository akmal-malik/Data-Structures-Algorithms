#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Spiral Matrix
//
// Given an m x n matrix, return all elements of the matrix
// in spiral order.
//
// Example:
// Input:
// 1 2 3
// 4 5 6
// 7 8 9
//
// Output:
// [1, 2, 3, 6, 9, 8, 7, 4, 5]
//
// Approach:
// - Maintain four boundaries: top, bottom, left, right.
// - Traverse:
//   1. Left → Right
//   2. Top → Bottom
//   3. Right → Left
//   4. Bottom → Top
// - Shrink boundaries after each traversal.
//
// Time Complexity: O(m * n)
// Space Complexity: O(1) (excluding output)
// ============================================================

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int> result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            result.push_back(matrix[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
    }

    return result;
}

int main() {

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result)
        cout << num << " ";

    return 0;
}

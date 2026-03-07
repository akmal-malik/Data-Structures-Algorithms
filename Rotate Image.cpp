#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Rotate Image
//
// Rotate an n x n matrix by 90 degrees clockwise in-place.
//
// Example:
// Input:
// 1 2 3
// 4 5 6
// 7 8 9
//
// Output:
// 7 4 1
// 8 5 2
// 9 6 3
//
// Approach:
// - Step 1: Transpose the matrix (swap rows and columns).
// - Step 2: Reverse each row.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// ============================================================

void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse rows
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    rotate(matrix);

    cout << "Rotated Matrix:\n";

    for (auto &row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}

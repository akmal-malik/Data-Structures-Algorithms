#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Problem: Set Matrix Zeroes
//
// If an element is 0, set its entire row and column to 0.
//
// Example:
// Input:
// 1 1 1
// 1 0 1
// 1 1 1
//
// Output:
// 1 0 1
// 0 0 0
// 1 0 1
//
// Approach:
// - Use first row and first column as markers.
// - Mark rows and columns that should become zero.
// - Update matrix based on markers.
//
// Time Complexity: O(m * n)
// Space Complexity: O(1)
// ============================================================

void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRow = false, firstCol = false;

    for (int i = 0; i < m; i++)
        if (matrix[i][0] == 0)
            firstCol = true;

    for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0)
            firstRow = true;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++)
                matrix[i][j] = 0;
        }
    }

    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++)
                matrix[i][j] = 0;
        }
    }

    if (firstRow)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;

    if (firstCol)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
}

int main() {

    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix);

    cout << "Matrix after setting zeroes:\n";

    for (auto &row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}

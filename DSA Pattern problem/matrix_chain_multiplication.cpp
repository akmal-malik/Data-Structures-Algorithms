// Problem: Matrix chain multiplication
// ------------------------------------------------------------
// Problem Description:
// Given a sequence of matrices, you are required to determine the most efficient way to multiply these matrices together. The problem is to find an optimal order to multiply these matrices such that the total number of operations needed is minimized.
// ------------------------------------------------------------
// Approach: Dynamic Programming (Tabulation)
// We use dynamic programming to solve this problem by breaking it down into subproblems and solving each subproblem only once. We store the results of these subproblems in a 2D table to avoid redundant calculations.
// ------------------------------------------------------------
// Time Complexity: O(n^3)
// The time complexity is O(n^3) because we have three nested loops iterating over the matrix dimensions.
// ------------------------------------------------------------
// Space Complexity: O(n^2)
// The space complexity is O(n^2) due to the storage of results in a 2D table.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixChainMultiplication(vector<int>& matrices) {
        int n = matrices.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int L = 2; L < n; ++L) {
            for (int i = 1; i < n - L + 1; ++i) {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k <= j - 1; ++k) {
                    int cost = dp[i][k] + dp[k+1][j] + matrices[i-1] * matrices[k] * matrices[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        return dp[1][n-1];
    }
};
// Problem: Unique binary search trees
// ------------------------------------------------------------
// Problem Description:
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use dynamic programming to solve this problem. Define dp[i] as the number of unique BSTs that can be formed with numbers from 1 to i. 
// The value of dp[i] can be calculated by summing up dp[j-1] * dp[i-j] for j in range [1, i], which represents all possible ways to choose a root node and combine left and right subtrees.
// ------------------------------------------------------------
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
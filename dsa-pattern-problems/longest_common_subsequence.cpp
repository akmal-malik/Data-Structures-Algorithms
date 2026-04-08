// Problem: Longest common subsequence
// ------------------------------------------------------------
// Problem Description:
// Given two sequences, find the length of their longest common subsequence (LCS). A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
// For example, "ace" is a subsequence of "abcde" while "aec" is not.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use a 2D DP table where dp[i][j] represents the length of LCS of the first i characters in str1 and the first j characters in str2. 
// Fill the table by comparing characters of both strings and decide whether to take that character into account or not.
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
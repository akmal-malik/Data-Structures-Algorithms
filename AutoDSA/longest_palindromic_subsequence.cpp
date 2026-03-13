// Problem: Longest palindromic subsequence
// ------------------------------------------------------------
// Problem Description:
// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// The problem can be solved using dynamic programming by creating a 2D DP table where dp[i][j] represents the length of the longest palindromic subsequence in the substring s[i..j].
// We initialize the table with the base case where single characters are palindromes of length 1. Then, we fill the table by comparing characters from both ends of the substring and updating the table accordingly.
// ------------------------------------------------------------
// Time Complexity: O(n^2), where n is the length of the string s.
// Space Complexity: O(n^2), where n is the length of the string s.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1; // Single character is a palindrome of length 1
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2; // Characters match, extend palindrome length
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // Characters do not match, take maximum
                }
            }
        }
        return dp[0][n - 1];
    }
};
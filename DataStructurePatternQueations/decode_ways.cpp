// Problem: Decode ways
// ------------------------------------------------------------
// Problem Description:
// Given a string s containing only digits, return the number of ways to decode it.
// A message containing letters from A-Z can be encoded into numbers using the following mapping:
// 'A' -> "1", 'B' -> "2", ..., 'Z' -> "26".
// To decode a given string, we need to count all possible valid mappings.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use a DP array where dp[i] represents the number of ways to decode the substring s[0:i+1].
// Initialize dp[0] = 1 because there's one way to decode an empty string.
// Iterate through the string, updating dp[i] based on valid decoding rules:
// - If the current character is not '0', dp[i] += dp[i-1]
// - If the last two characters form a number between 10 and 26, dp[i] += dp[i-2]
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            if (s[i] != '0') dp[i] += dp[i-1];
            int num = stoi(s.substr(i-1, 2));
            if (num >= 10 && num <= 26) dp[i] += dp[max(0, i-2)];
        }
        
        return dp[n-1];
    }
};
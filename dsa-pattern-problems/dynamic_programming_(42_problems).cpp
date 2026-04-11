// Problem: Dynamic Programming (42 problems)
// ------------------------------------------------------------
// Problem Description:
// You are given a string s and an array of strings words. All the strings of words are of the same length.
// Return true if you can make s by concatenating zero or more of the strings in words. 
// Note that the order of the strings in words matters, so we cannot concatenate in reverse order.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use a DP array where dp[i] is true if the first i characters of s can be formed by concatenating strings from words.
// Initialize dp[0] as true since an empty string can always be formed.
// Iterate through each character of s, and for each position, check if any prefix ending at that position can be formed by a word in words.
// If so, update the DP array accordingly.
// ------------------------------------------------------------
// Time Complexity: O(n * m)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormString(string s, vector<string>& words) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (const string& word : words) {
                if (i >= word.length() && s.substr(i - word.length(), word.length()) == word) {
                    dp[i] = dp[i] || dp[i - word.length()];
                }
            }
        }
        
        return dp[n];
    }
};
// Problem: Word break
// ------------------------------------------------------------
// Problem Description:
// Given a non-empty string s and a dictionary wordDict containing 
// a list of non-empty words, determine if s can be segmented into 
// a sequence of one or more dictionary words.
// 
// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use a boolean DP array to mark whether a substring can be segmented into 
// words from the dictionary. dp[i] is true if the substring s[0...i-1] can 
// be segmented into dictionary words.
// 
// Initialize dp[0] as true because an empty string is considered 
// to be segmented by definition.
//
// For each character in the string, check all possible substrings ending at that 
// character. If a substring s[j...i-1] exists and it is in the dictionary, set 
// dp[i] = true if dp[j] is also true.
//
// Finally, return dp[n], where n is the length of the string.
// ------------------------------------------------------------
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
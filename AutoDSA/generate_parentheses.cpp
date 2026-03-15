// Problem: Generate Parentheses
// ------------------------------------------------------------
// Problem Description:
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// ------------------------------------------------------------
// Approach: Backtracking
// Using backtracking to explore all possible combinations and prune those that are invalid.
// ------------------------------------------------------------
// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};
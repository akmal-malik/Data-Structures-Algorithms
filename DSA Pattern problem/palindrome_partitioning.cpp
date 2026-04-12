// Problem: Palindrome partitioning
// ------------------------------------------------------------
// Problem Description:
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// ------------------------------------------------------------
// Approach: Backtracking
// The idea is to use a backtracking approach to explore all possible partitions of the string. For each partition, we check if it is a palindrome and if so, add it to the current partition and proceed to the next part of the string. If the entire string is partitioned, we add the current partition to the result.
// ------------------------------------------------------------
// Time Complexity: O(2^n), where n is the length of the string. In the worst case, we have to explore all possible partitions.
// Space Complexity: O(n), where n is the length of the string. The space is used for the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(string s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
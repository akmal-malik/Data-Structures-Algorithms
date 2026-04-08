// Problem: Longest common prefix
// ------------------------------------------------------------
// Problem Description:
// Given a vector of strings strs, write a function to find the longest common prefix string among them. 
// If there is no common prefix, return an empty string "".
// ------------------------------------------------------------
// Approach: Vertical scanning
// Iterate through the characters of the first string, and compare them with the corresponding characters of the other strings. 
// Stop when a mismatch is found or the end of any string is reached.
// ------------------------------------------------------------
// Time Complexity: O(S), where S is the sum of all characters in all strings.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};
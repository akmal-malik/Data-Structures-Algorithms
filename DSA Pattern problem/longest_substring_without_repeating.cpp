// Problem: Longest substring without repeating
// ------------------------------------------------------------
// Problem Description:
// Given a string s, find the length of the longest substring without repeating characters.
// ------------------------------------------------------------
// Approach: Sliding Window
// Using a hash map to store the last seen index of each character. 
// Iterate through the string, and for each character, update the start of the window if it's within the current window.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(min(n, m)), where n is the length of the string and m is the size of the character set
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= start) {
                start = lastSeen[s[i]] + 1;
            } else {
                maxLength = max(maxLength, i - start + 1);
            }
            lastSeen[s[i]] = i;
        }

        return maxLength;
    }
};
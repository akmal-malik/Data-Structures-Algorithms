// Problem: Longest repeating character replacement
// ------------------------------------------------------------
// Problem Description:
// Given a string s and an integer k, you can replace up to k characters in the string with any other character so that the resulting string contains the same character repeated at least n times. Find the length of the longest possible substring with repeated characters after performing at most k replacements.
// ------------------------------------------------------------
// Approach: Sliding Window
// Use a sliding window to keep track of the character counts within the window. Maintain a variable to track the maximum frequency of any single character in the current window. The size of the window minus the maximum frequency indicates how many replacements are needed. If this number exceeds k, shrink the window from the left. The size of the window at any point is the length of the longest substring with repeated characters.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, start = 0, maxLength = 0;
        vector<int> count(26, 0);

        for (int end = 0; end < s.size(); ++end) {
            count[s[end] - 'A']++;
            maxFreq = max(maxFreq, count[s[end] - 'A']);

            if ((end - start + 1) - maxFreq > k) {
                count[s[start] - 'A']--;
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
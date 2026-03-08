// Problem: Longest Substring Without Repeating Characters
// ------------------------------------------------------------
// Given a string s, find the length of the longest substring
// without repeating characters.
//
// A substring is a contiguous sequence of characters.
//
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The longest substring without repeating
// characters is "abc".
//
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The longest substring is "b".
//
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke".
//
// Note:
// The answer must be a substring, not a subsequence.
//
// Constraints:
// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols, and spaces.
//
// ------------------------------------------------------------
// Approach: Sliding Window + Hash Set
//
// Use two pointers to maintain a window of unique characters.
//
// Steps:
// 1. Expand the window by moving the right pointer.
// 2. If a duplicate character appears, move the left pointer
//    until the duplicate is removed.
// 3. Track the maximum length of the valid window.
//
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(min(n, charset))
// ------------------------------------------------------------

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++) {
            while(seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

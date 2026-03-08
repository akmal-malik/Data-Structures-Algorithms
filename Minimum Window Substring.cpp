// Problem: Minimum Window Substring
// ------------------------------------------------------------
// Given two strings s and t of lengths m and n respectively,
// return the minimum window substring of s such that every
// character in t (including duplicates) is included in the window.
//
// If there is no such substring, return an empty string "".
//
// The answer is guaranteed to be unique.
//
// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
//
// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
//
// Example 3:
// Input: s = "a", t = "aa"
// Output: ""
//
// Constraints:
// 1 <= m, n <= 10^5
// s and t consist of uppercase and lowercase English letters.
//
// ------------------------------------------------------------
// Approach: Sliding Window + Frequency Count
//
// Steps:
// 1. Store frequency of characters from t.
// 2. Expand the window using the right pointer.
// 3. Reduce the required count when matching characters appear.
// 4. When all characters are satisfied, try shrinking the window
//    from the left to minimize the window size.
// 5. Track the smallest valid window.
//
// ------------------------------------------------------------
// Time Complexity: O(m + n)
// Space Complexity: O(1)
// ------------------------------------------------------------

#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128, 0);

        for(char c : t)
            count[c]++;

        int left = 0;
        int right = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()) {
            if(count[s[right]] > 0)
                required--;

            count[s[right]]--;
            right++;

            while(required == 0) {
                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                count[s[left]]++;
                if(count[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

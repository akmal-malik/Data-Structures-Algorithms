// Problem: Longest palindromic substring
// ------------------------------------------------------------
// Problem Description:
// Given a string s, return the longest palindromic substring in s.
// A palindromic string reads the same backward as forward.
// ------------------------------------------------------------
// Approach: Expand Around Center
// The idea is to consider each character and each pair of consecutive characters as the center of a potential palindrome.
// Expand outwards as long as the substring remains a palindrome.
// Track the longest palindrome found during the process.
// ------------------------------------------------------------
// Time Complexity: O(n^2), where n is the length of the string.
// Space Complexity: O(1), only using a constant amount of extra space.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i); // Odd length palindromes
            expandAroundCenter(i, i + 1); // Even length palindromes
        }
        
        return s.substr(start, maxLength);
    }
};
// Problem: Valid Palindrome
// ------------------------------------------------------------
// Problem Description:
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// 
// Given a string s, return true if it is a palindrome, or false otherwise.
// 
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// 
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// 
// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters. Since an empty string reads the same forward and backward, it is a palindrome.
// 
// Constraints:
// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.
// 
// ------------------------------------------------------------
// Approach: Two-Pointer Technique
// Use two pointers, one starting at the beginning and one at the end of the string. Move them towards each other, skipping non-alphanumeric characters, and comparing the characters at these pointers. If they are not equal at any point, return false. If the pointers meet or cross without finding any mismatch, return true.
// 
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};
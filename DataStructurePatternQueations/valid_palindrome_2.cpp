// Problem: Valid palindrome 2
// ------------------------------------------------------------
// Problem Description:
// Given a string s, return true if the s can be palindrome after deleting at most one character from it.
// ------------------------------------------------------------
// Approach: Two Pointers
// The idea is to use two pointers to compare characters from both ends of the string. If they are the same, move both pointers inward. If they are not the same, we have two choices: delete the character at the left pointer or the character at the right pointer. We need to check both possibilities and see if either results in a palindrome.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
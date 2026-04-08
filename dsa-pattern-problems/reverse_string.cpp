// Problem: Reverse string
// ------------------------------------------------------------
// Problem Description:
// Given a string s, reverse the order of characters in s.
// ------------------------------------------------------------
// Approach: Two-pointer technique
// Initialize two pointers, one at the beginning and one at the end of the string.
// Swap the characters at these pointers and move the pointers towards the center.
// Continue this process until the pointers meet or cross each other.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as we are modifying the string in place.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        
        return s;
    }
};
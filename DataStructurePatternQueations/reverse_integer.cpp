// Problem: Reverse integer
// ------------------------------------------------------------
// Problem Description:
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// ------------------------------------------------------------
// Approach: Integer Reversal
// Convert the integer to a string, reverse the string, and then convert it back to an integer. Handle edge cases such as overflow and negative numbers.
// ------------------------------------------------------------
// Time Complexity: O(d), where d is the number of digits in the integer.
// Space Complexity: O(d) for storing the reversed string.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (s[0] == '-') {
            reverse(s.begin() + 1, s.end());
        } else {
            reverse(s.begin(), s.end());
        }
        long long result = stoll(s);
        if (result < INT_MIN || result > INT_MAX) {
            return 0;
        }
        return (int)result;
    }
};
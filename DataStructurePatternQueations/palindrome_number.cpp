// Problem: Palindrome number
// ------------------------------------------------------------
// Problem Description:
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// For example, 121 is a palindrome while 123 is not.
// ------------------------------------------------------------
// Approach: Reverse Integer
// Convert the integer to a string and compare it with its reverse.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of digits in the integer.
// Space Complexity: O(n) due to the additional string storage.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        string rev = string(str.rbegin(), str.rend());
        return str == rev;
    }
};
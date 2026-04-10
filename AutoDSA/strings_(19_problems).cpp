// Problem: Strings (19 problems)
// ------------------------------------------------------------
// Problem Description:
// Implement strStr(). Given two strings needle and haystack, return the index of the first occurrence of needle in haystack. If needle is not part of haystack, return -1.
// For example, given haystack = "hello" and needle = "ll", return 2.
// ------------------------------------------------------------
// Approach: Brute Force
// Iterate through each character of haystack and check if the substring starting at that position matches needle.
// Time Complexity: O(n * m), where n is the length of haystack and m is the length of needle.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            bool match = true;
            for (int j = 0; j < needle.length(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }
};
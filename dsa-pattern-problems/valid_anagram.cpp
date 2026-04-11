// Problem: Valid Anagram
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Sorting
// Sort both strings and compare them. If they are equal, then one string is an anagram of the other.
// ------------------------------------------------------------
// Time Complexity: O(n log n)
// Space Complexity: O(1) if we ignore the space required for sorting
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
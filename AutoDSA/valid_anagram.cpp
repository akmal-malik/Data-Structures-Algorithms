// Problem: Valid Anagram
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Frequency Counting
// We can use frequency maps (or arrays since the character set is limited to lowercase English letters) to count the occurrences of each character in both strings.
// If the frequency counts of all characters are identical for both strings, then t is an anagram of s.
// We can optimize this by iterating through one string to increment counts and through the other to decrement counts. If all counts end up being zero, they are anagrams.
// ------------------------------------------------------------
// Time Complexity: O(N + M) where N is the length of s and M is the length of t. If N=M, it's O(N).
// Space Complexity: O(1) because the size of the frequency array is constant (26 for lowercase English letters).
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> counts(26, 0);

        for (char c : s) {
            counts[c - 'a']++;
        }

        for (char c : t) {
            counts[c - 'a']--;
            if (counts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
// Problem: Valid Anagram
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Frequency Counting
// We can solve this by counting the frequency of each character in both strings.
// If the lengths of the strings are different, they cannot be anagrams.
// We use an array (or a hash map) to store the counts of characters.
// Iterate through the first string, incrementing the count for each character.
// Then, iterate through the second string, decrementing the count for each character.
// If at any point a count becomes negative, it means the second string has more of that character than the first, so they are not anagrams.
// Finally, after processing both strings, all counts in the frequency array should be zero if they are anagrams.
// ------------------------------------------------------------
// Time Complexity: O(N), where N is the length of the strings. We iterate through both strings once.
// Space Complexity: O(1), as the frequency array size is constant (26 for lowercase English letters).
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> char_counts(26, 0);

        for (char c : s) {
            char_counts[c - 'a']++;
        }

        for (char c : t) {
            char_counts[c - 'a']--;
            if (char_counts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
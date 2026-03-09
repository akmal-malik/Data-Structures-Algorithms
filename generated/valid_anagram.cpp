// Problem: Valid Anagram
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Frequency Map
// We can count the frequency of each character in both strings. If the frequency maps are identical, then the strings are anagrams. We can use an array of size 26 (for lowercase English letters) as a frequency map. Iterate through the first string, incrementing the count for each character. Then, iterate through the second string, decrementing the count for each character. If at any point a count becomes negative, or if after processing the second string any count is not zero, then they are not anagrams.
// ------------------------------------------------------------
// Time Complexity: O(N), where N is the length of the strings. We iterate through both strings once.
// Space Complexity: O(1), as the frequency map has a fixed size (26 for lowercase English letters).
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        // This check is technically redundant if the lengths are equal and no frequency went negative.
        // However, it adds robustness if the length check was missed or for general understanding.
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
// Problem: Valid Anagram
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Frequency Counting (Hash Map/Array)
// The core idea is that two strings are anagrams if and only if they have the same characters with the same frequencies.
// We can use a hash map (or a fixed-size array if we assume ASCII or a limited character set) to store the frequency of each character in the first string `s`.
// Then, we iterate through the second string `t`. For each character in `t`, we decrement its count in our frequency map.
// If at any point we encounter a character in `t` that is not in `s` (its count is already zero or negative before decrementing), or if after processing `t` the frequency map contains any non-zero counts, then `t` is not an anagram of `s`.
// Finally, after iterating through `t`, all counts in the frequency map must be zero for `t` to be an anagram of `s`.
//
// A more optimized approach for this specific problem, given that we are dealing with lowercase English letters (a-z), is to use a fixed-size array of size 26 instead of a general hash map. This is more efficient due to direct indexing.
// ------------------------------------------------------------
// Time Complexity: O(N + M) where N is the length of s and M is the length of t.
// We iterate through string s once and string t once.
// Space Complexity: O(1) if using a fixed-size array (26 elements for lowercase English alphabet).
// If a hash map were used for an arbitrary character set, it could be O(K) where K is the number of unique characters.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int freq[26] = {0};

        // Count character frequencies for string s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Decrement character frequencies for string t
        for (char c : t) {
            freq[c - 'a']--;
            // If at any point a character count goes below zero, it means t has more of this char than s,
            // or t has a character not present in s.
            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        // After iterating through t, all counts in freq should be zero if they are anagrams.
        // This check is technically redundant because if lengths are equal and no count went negative,
        // all counts must naturally be zero. However, it can be kept for clarity or if initial length check was missed.
        // For this problem, the check `if (freq[c - 'a'] < 0)` is sufficient.
        // The explicit loop below confirms this:
        // for (int i = 0; i < 26; ++i) {
        //     if (freq[i] != 0) {
        //         return false;
        //     }
        // }

        return true;
    }
};
// Problem: Valid Anagram
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, write a function to determine if t is an anagram of s.
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Frequency Count
// We count the frequency of each character in both strings and compare the counts.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1) since the size of the count arrays is fixed (26 for English alphabet)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> count(26, 0);
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : t) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
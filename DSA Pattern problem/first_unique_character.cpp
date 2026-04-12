// Problem: First unique character
// ------------------------------------------------------------
// Problem Description:
// Given a string s, find the first non-repeating character in it and return its index. 
// If it doesn't exist, return -1.
// ------------------------------------------------------------
// Approach: Hash Map
// Use a hash map to store the frequency of each character. Then iterate through the string again to find the first character with a frequency of 1.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1) since the character set size is fixed
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
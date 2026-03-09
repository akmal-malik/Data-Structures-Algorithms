// Problem: Group anagrams
// ------------------------------------------------------------
// Problem Description:
// Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Sorting strings
// The core idea is that anagrams will have the same characters, just in a different order. If we sort the characters of each string alphabetically, all anagrams will produce the same sorted string. We can use a hash map where the key is the sorted string and the value is a list of strings that correspond to that sorted key. We iterate through the input array of strings, sort each string, and then add the original string to the list associated with its sorted version in the hash map. Finally, we collect all the lists from the hash map's values to form the result.
// ------------------------------------------------------------
// Time Complexity: O(N * K * log K) where N is the number of strings and K is the maximum length of a string. Sorting each string takes O(K * log K) time, and we do this for N strings. Map operations (insertion and retrieval) take average O(K) time for string keys.
// Space Complexity: O(N * K) in the worst case, where N is the number of strings and K is the maximum length of a string. This is to store all the strings in the hash map and the resulting grouped lists.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            anagramGroups[sorted_s].push_back(s);
        }

        vector<vector<string>> result;
        for (auto const& [key, val] : anagramGroups) {
            result.push_back(val);
        }

        return result;
    }
};
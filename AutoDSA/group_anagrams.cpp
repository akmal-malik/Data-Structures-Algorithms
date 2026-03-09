// Problem: Group anagrams
// ------------------------------------------------------------
// Problem Description:
// Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Hash Map with Sorted Strings
// We can use a hash map where the key is the sorted version of a string and the value is a list of strings that are anagrams of each other.
// For each string in the input array, we sort its characters to create a unique key.
// We then add the original string to the list associated with this key in the hash map.
// Finally, we collect all the lists from the hash map values to form the grouped anagrams.
// ------------------------------------------------------------
// Time Complexity: O(N * K * log K), where N is the number of strings and K is the maximum length of a string. Sorting each string takes O(K log K).
// Space Complexity: O(N * K), to store the hash map.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_groups;

        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagram_groups[sorted_str].push_back(str);
        }

        vector<vector<string>> result;
        for (auto const& [key, val] : anagram_groups) {
            result.push_back(val);
        }

        return result;
    }
};
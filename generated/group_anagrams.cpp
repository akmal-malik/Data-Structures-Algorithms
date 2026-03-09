// Problem: Group anagrams
// ------------------------------------------------------------
// Problem Description:
// Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Sorting and Hashing
// For each string, we can create a canonical representation by sorting its characters. Anagrams will have the same sorted string. We use a hash map (unordered_map in C++) to store these sorted strings as keys and vectors of their original strings as values. We iterate through the input array, sort each string, and add the original string to the corresponding vector in the hash map. Finally, we collect all the vectors from the hash map's values to form the result.
// ------------------------------------------------------------
// Time Complexity: O(NK log K) where N is the number of strings and K is the maximum length of a string. Sorting each string takes O(K log K).
// Space Complexity: O(NK) in the worst case, where N is the number of strings and K is the maximum length of a string, to store the hash map and the result.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (auto const& [key, val] : anagramGroups) {
            result.push_back(val);
        }

        return result;
    }
};
// Problem: Group anagrams
// ------------------------------------------------------------
// Problem Description:
// Given an array of strings strs, group the anagrams together. 
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.
// Example:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat"],["ate","eat","tea"],["tan"]]
// ------------------------------------------------------------
// Approach: Hash Table
// Use a hash table where the key is a sorted version of the string and the value is a list of anagrams.
// Iterate through each string, sort it, and use the sorted string as the key in the hash table.
// Append the original string to the list corresponding to its sorted key.
// ------------------------------------------------------------
// Time Complexity: O(NKlogK), where N is the number of strings and K is the maximum length of a string.
// Space Complexity: O(NK), to store the hash table.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& pair : anagrams) {
            result.push_back(pair.second);
        }
        return result;
    }
};
// Problem: Group anagrams
// ------------------------------------------------------------
// Problem Description:
// Given an array of strings, group the anagrams together. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// For example, given ["eat", "tea", "tan", "ate", "nat", "bat"], the output should be [["eat","tea"],["tan","nat"],["bat"]].
// ------------------------------------------------------------
// Approach: Hash Map
// We use a hash map where the key is a sorted version of the string (to identify anagrams) and the value is a list of strings that are anagrams.
// For each string, we sort it and use the sorted string as the key in the hash map. We then append the original string to the corresponding list.
// ------------------------------------------------------------
// Time Complexity: O(NK log K), where N is the number of strings and K is the maximum length of a string. Sorting takes O(K log K) time for each string.
// Space Complexity: O(NK) to store the hash map and the result.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            anagrams[sorted_s].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : anagrams) {
            result.push_back(pair.second);
        }
        return result;
    }
};
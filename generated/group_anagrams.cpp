// Problem: Group anagrams
// ------------------------------------------------------------
// Problem Description:
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// ------------------------------------------------------------
// Approach: Hash Map with Sorted Strings
// The core idea is that anagrams, when their characters are sorted alphabetically, will result in the same string. We can use a hash map where the key is the sorted version of a string and the value is a list of all strings that produce this sorted key. We iterate through the input array, sort each string, and use it as a key to add the original string to the corresponding list in the hash map. Finally, we collect all the lists from the hash map's values.
// ------------------------------------------------------------
// Time Complexity: O(N * K log K) where N is the number of strings and K is the maximum length of a string. Sorting each string takes O(K log K), and we do this for N strings.
// Space Complexity: O(N * K) in the worst case, where N is the number of strings and K is the average length of a string, to store the hash map and the resulting groups.
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
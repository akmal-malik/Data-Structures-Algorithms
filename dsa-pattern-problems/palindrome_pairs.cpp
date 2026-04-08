// Problem: Palindrome Pairs
// ------------------------------------------------------------
// Problem Description:
// Given a list of unique words, return all the pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e., words[i] + words[j] is a palindrome.
// ------------------------------------------------------------
// Approach: Hash Table
// Iterate through each word and check if there exists another word such that when concatenated with the current word, it forms a palindrome. Use hash table to store reversed prefixes and their indices for quick lookup.
// ------------------------------------------------------------
// Time Complexity: O(N * K^2) where N is the number of words and K is the maximum length of a word
// Space Complexity: O(N * K)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordIndex;
        for (int i = 0; i < words.size(); ++i) {
            wordIndex[words[i]] = i;
        }

        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());

            // Check if the reversed word is in the dictionary and not the same as the current word
            if (wordIndex.count(reversedWord) && wordIndex[reversedWord] != i) {
                result.push_back({i, wordIndex[reversedWord]});
            }

            for (int j = 1; j < words[i].size(); ++j) {
                string prefix = words[i].substr(0, j);
                string suffix = words[i].substr(j);

                if (isPalindrome(suffix)) {
                    string reversedPrefix = prefix;
                    reverse(reversedPrefix.begin(), reversedPrefix.end());
                    if (wordIndex.count(reversedPrefix)) {
                        result.push_back({i, wordIndex[reversedPrefix]});
                    }
                }

                if (isPalindrome(prefix)) {
                    string reversedSuffix = suffix;
                    reverse(reversedSuffix.begin(), reversedSuffix.end());
                    if (wordIndex.count(reversedSuffix) && wordIndex[reversedSuffix] != i) {
                        result.push_back({wordIndex[reversedSuffix], i});
                    }
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }
};
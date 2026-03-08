// Problem: Substring with Concatenation of All Words
// ------------------------------------------------------------
// You are given a string s and an array of strings words.
// All strings in words have the same length.
//
// A concatenated string is a string that contains every word
// in words exactly once in any permutation.
//
// Return all starting indices of substrings in s that are a
// concatenation of all words.
//
// Example 1:
// Input:
// s = "barfoothefoobarman"
// words = ["foo","bar"]
//
// Output:
// [0,9]
//
// Explanation:
// "barfoo" at index 0 and "foobar" at index 9 are valid.
//
// Example 2:
// Input:
// s = "wordgoodgoodgoodbestword"
// words = ["word","good","best","word"]
//
// Output:
// []
//
// Example 3:
// Input:
// s = "barfoofoobarthefoobarman"
// words = ["bar","foo","the"]
//
// Output:
// [6,9,12]
//
// ------------------------------------------------------------
// Approach: Sliding Window + Hash Map
//
// Key Observations:
// 1. Every word has the same length.
// 2. The total window size must be:
//      wordLen * number_of_words
//
// Steps:
// 1. Store frequency of each word in a hashmap.
// 2. Slide the window in steps of wordLen.
// 3. Extract words from the string and track counts.
// 4. If a word appears too many times, shrink the window.
// 5. If all words match, store the starting index.
//
// ------------------------------------------------------------
// Time Complexity: O(n * wordLen)
// Space Complexity: O(words)
// ------------------------------------------------------------

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();

        unordered_map<string,int> wordFreq;

        for(string &w : words)
            wordFreq[w]++;

        for(int i = 0; i < wordLen; i++) {

            unordered_map<string,int> seen;
            int left = i;
            int count = 0;

            for(int right = i; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                if(wordFreq.count(word)) {

                    seen[word]++;
                    count++;

                    while(seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count == wordCount) {
                        result.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};

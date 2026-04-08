// Problem: Reverse words in string
// ------------------------------------------------------------
// Problem Description:
// Given a string, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// ------------------------------------------------------------
// Approach: Stack
// Use a stack to reverse each word and a stringstream to handle the input string and output the result.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n) due to the stack and the extra string.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        stack<string> words;
        
        while (ss >> word) {
            reverse(word.begin(), word.end());
            words.push(word);
        }
        
        while (!words.empty()) {
            result += words.top();
            words.pop();
            if (!words.empty()) {
                result += " ";
            }
        }
        
        return result;
    }
};
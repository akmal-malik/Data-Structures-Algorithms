// Problem: Recursion & Backtracking (18 problems)
// ------------------------------------------------------------
// Problem Description:
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// Note: The digit 0 and 1 do not map to any letters.
// ------------------------------------------------------------
// Approach: Backtracking
// Use backtracking to generate all possible combinations by mapping each digit to its corresponding letters and exploring all possibilities recursively.
// ------------------------------------------------------------
// Time Complexity: O(4^n) in the worst case, where n is the number of digits. This is because a digit can map to up to 4 letters.
// Space Complexity: O(n) due to the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> result;
        backtrack(result, phoneMap, digits, "", 0);
        return result;
    }
private:
    void backtrack(vector<string>& result, unordered_map<char, string>& phoneMap, string& digits, string current, int index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[index];
        string letters = phoneMap[digit];
        
        for (char letter : letters) {
            backtrack(result, phoneMap, digits, current + letter, index + 1);
        }
    }
};
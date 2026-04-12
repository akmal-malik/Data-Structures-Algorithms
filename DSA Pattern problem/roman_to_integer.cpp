// Problem: Roman to integer
// ------------------------------------------------------------
// Problem Description:
// Given a roman numeral, convert it to an integer.
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// For example, 2 is written as II in Roman numeral, just two one's added together. 
// 12 is written as XII, which is simply X + II. 
// The number 27 is written as XXVII, which is XX + V + II.
// Roman numerals are usually written largest to smallest from left to right. 
// However, the numeral for four is not IIII. Instead, the number four is written as IV. 
// Because the one is before the five we subtract it making four. 
// The same principle applies to the number nine, which is written as IX.
// There are six instances where subtraction is used:
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.
// ------------------------------------------------------------
// Approach: HashMap + Simulation
// Use a HashMap to store the value of each Roman symbol. 
// Iterate through the string from left to right. 
// If the current symbol is less than the next symbol, subtract its value from the total. 
// Otherwise, add its value to the total.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the length of the input string.
// Space Complexity: O(1), as the size of the HashMap is constant.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }
        return result;
    }
};
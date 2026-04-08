// Problem: Remove outermost parentheses
// ------------------------------------------------------------
// Problem Description:
// Given a string S of '(' and ')' parentheses, remove the outermost parentheses of every balanced substring in the string.
// A balanced substring is a substring that has an equal number of '(' and ')'.
// You may assume that all input strings are balanced.
// The answer is always a valid string of parentheses.
// ------------------------------------------------------------
// Approach: Stack
// Traverse the string and use a stack to keep track of the balance of parentheses. When a balanced substring is found, skip the first and last characters.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> st;
        string result = "";
        for (char c : S) {
            if (c == '(') {
                if (!st.empty()) {
                    result += c;
                }
                st.push(c);
            } else {
                st.pop();
                if (!st.empty()) {
                    result += c;
                }
            }
        }
        return result;
    }
};
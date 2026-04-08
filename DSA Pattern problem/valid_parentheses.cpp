// Problem: Valid parentheses
// ------------------------------------------------------------
// Problem Description:
// Given a string s consisting of '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// - Open brackets must be closed by the same type of brackets.
// - Open brackets must be closed in the correct order.
// - Every close bracket has a corresponding open bracket of the same type.
// ------------------------------------------------------------
// Approach: Stack
// Use a stack to keep track of opening brackets. For each character in the string, if it is an opening bracket, push it onto the stack. If it is a closing bracket, check if the stack is empty or if the top of the stack does not match the corresponding opening bracket. If either condition is true, the string is invalid. If the stack is empty at the end, the string is valid.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n) in the worst case, where all characters are opening brackets.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty()) return false;
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
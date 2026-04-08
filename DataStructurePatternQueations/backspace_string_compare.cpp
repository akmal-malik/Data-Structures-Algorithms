// Problem: Backspace string compare
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// ------------------------------------------------------------
// Approach: Stack
// Use stack to simulate the backspace operation and compare the two strings.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        
        for(char c : s) {
            if(c == '#') {
                if(!stk1.empty()) stk1.pop();
            } else {
                stk1.push(c);
            }
        }
        
        for(char c : t) {
            if(c == '#') {
                if(!stk2.empty()) stk2.pop();
            } else {
                stk2.push(c);
            }
        }
        
        return stk1 == stk2;
    }
};
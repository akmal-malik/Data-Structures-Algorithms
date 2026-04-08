// Problem: Minimum window substring
// ------------------------------------------------------------
// Problem Description:
// Given two strings s and t, return the minimum window in s which will 
// contain all the characters in t. If there is no such window in s, 
// return the empty string "".
// 
// Note: If there is such a window, it is guaranteed that there will 
// always be only one unique minimum window in s.
// ------------------------------------------------------------
// Approach: Sliding Window
// This approach uses the sliding window technique to find the minimum 
// window in s that contains all characters of t. We maintain a 
// frequency map of characters in t and use two pointers to expand and 
// contract the window in s.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int tCount[256] = {0}, sCount[256] = {0};
        int formed = 0, required = t.size(), ans = INT_MAX, left = 0, right = 0, ansLeft = 0;

        for(char c : t) {
            tCount[c]++;
        }

        while(right < s.size()) {
            char c = s[right];
            right++;
            if(tCount[c] > 0) {
                sCount[c]++;
                if(sCount[c] == tCount[c]) {
                    formed++;
                }
            }

            while(left <= right && formed == required) {
                char d = s[left];
                left++;
                if(right - left + 1 < ans) {
                    ans = right - left + 1;
                    ansLeft = left - 1;
                }
                if(tCount[d] > 0) {
                    sCount[d]--;
                    if(sCount[d] < tCount[d]) {
                        formed--;
                    }
                }
            }
        }
        return (ans != INT_MAX) ? s.substr(ansLeft, ans) : "";
    }
};